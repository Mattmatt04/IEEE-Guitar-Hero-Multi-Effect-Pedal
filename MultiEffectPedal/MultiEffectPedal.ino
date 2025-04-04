#include "DaisyDuino.h"
#include "RingModulation.h"
#include "AntiMatterCompressor.h"
#include "MatterCompressor.h"
#include "Reverb.h"
#include "PitchShift.h"
#include "USPSDelay.h"
#include "AutoWah.h"

using namespace std;

DaisyHardware hw;

size_t num_channels;
static Oscillator osc;

bool effect = false;
float amplitude = 1.0;

int notes[3] = {261, 329, 392};  // C Arpeggio in hz (C, E, G)
int curEffect = 5;

// Works on DSY_SDRAM_BSS
RingModulation DSY_SDRAM_BSS RingMod;
AntiMatterCompressor DSY_SDRAM_BSS AMComp;
MatterCompressor DSY_SDRAM_BSS MComp;
Reverb DSY_SDRAM_BSS Rev;
AutoWah DSY_SDRAM_BSS AWah;

// Does not work on DSY_SDRAM_BSS
PitchShift PShift;
USPSDelay USPS; 

Switch button;

void MyCallback(float **in, float **out, size_t size) {
  for (size_t i = 0; i < size; i++) {
    float sig = osc.Process();
    //float sig = in[0][i];     //For Guitar Input
    float outL = sig;
    float outR = sig;

    // Alter input signal
    if(effect) {
      switch (curEffect) {
        case 0:
          outL = outR = RingMod.Process(sig);
          break;
        case 1:
          outL = outR = AMComp.Process(sig);
          break;
        case 2:
          outL = outR = MComp.Process(sig);
          break;
        case 3:
          Rev.Process(sig, &outL, &outR);
          break;
        case 4:
          outL = outR = PShift.Process(sig);
          break;
        case 5:
          outL = outR = USPS.Process(sig);
          break;
        case 6:
          outL = outR = AWah.Process(sig);
          break;
      }
    }

    // Output signal
    out[0][i] = outL;
    out[1][i] = outR;
  }
}

void setup() {
  float sample_rate;
  // Initialize for Daisy pod at 48kHz
  hw = DAISY.init(DAISY_SEED, AUDIO_SR_48K);
  num_channels = hw.num_channels;
  sample_rate = DAISY.get_samplerate();

  osc.Init(sample_rate);
  osc.SetFreq(261);
  osc.SetAmp(5.0);
  osc.SetWaveform(osc.WAVE_SAW);

  RingMod.Initialize(sample_rate);
  MComp.Initialize();
  Rev.Initialize(sample_rate);
  PShift.Initialize(sample_rate);
  USPS.Initialize(sample_rate);
  AWah.Initialize(sample_rate);

  Serial.begin(9600);
  button.Init(1000, false, 28, INPUT_PULLUP);

  DAISY.begin(MyCallback);
}

void playNote(int frequency, int duration) {
  osc.SetAmp(amplitude);
  osc.SetFreq(frequency);
  delay(duration);
  osc.SetAmp(0.0);
}

void loop() {
  // Play note sequence
  for(int i = 0; i < size(notes); i++) {
    playNote(notes[i], 1000);
    delay(1000);
  }

  // Delay an extra second before looping
  delay(1000);

  // Swap between Dry and Wet signal
  effect = !effect;

  // Toggle effect on/off LED
  analogWrite(15, effect * 255);
}
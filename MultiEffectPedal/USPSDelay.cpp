#include "DaisyDuino.h"
#include "USPSDelay.h"

void USPSDelay::Process(float input, float *outL, float *outR, int mode) {
  del_out = del.Read();
  sig_out = del_out + input;
  feedback = (del_out * 0.5f) + input;

  // Write to the delay
  del.Write(feedback);

  switch(mode) {
    // Normal Delay
    case 0:
      *outL = sig_out;
      *outR = sig_out;
      break;
    // Ping Pong Delay
    case 1:
      if(tick.Process()) {
        toggleOutput = !toggleOutput;
      }
      *outL = toggleOutput * sig_out;
      *outR = !toggleOutput * sig_out;
      break;
    // Panning Delay
    case 2:
      *outL = osc.Process() * sig_out;
      osc.PhaseAdd(0.5);  // Phase shift for cosine
      *outR = osc.Process() * sig_out;
      osc.PhaseAdd(0.5); // Reset phase shift
      break;
  }
}

void USPSDelay::Initialize(float sample_rate) {
  del.SetDelay(sample_rate * 0.25f);

  // Oscillator for Panning delay
  osc.Init(sample_rate);
  osc.SetFreq(0.5);
  osc.SetAmp(1.0);
  osc.SetWaveform(osc.WAVE_SIN);

  toggleOutput = true;
  tick.Init(5.0f, sample_rate);
}
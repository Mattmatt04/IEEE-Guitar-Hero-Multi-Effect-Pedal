#include "DaisyDuino.h"
#include "RingModulation.h"

float RingModulation::Process(float input) {
  float carrier_signal = carrier.Process();
  return input * carrier_signal;
}

void RingModulation::Initialize(float sample_rate) {
  carrier.Init(sample_rate);
  carrier.SetFreq(311);
  carrier.SetAmp(1.0);
  carrier.SetWaveform(carrier.WAVE_SIN);
}
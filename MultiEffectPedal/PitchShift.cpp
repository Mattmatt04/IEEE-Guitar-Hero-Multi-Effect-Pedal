#include "DaisyDuino.h"
#include "PitchShift.h"

float PitchShift::Process(float input) {
  return pitch.Process(input);
}

void PitchShift::Initialize(float sample_rate) {
  pitch.Init(sample_rate);
  pitch.SetTransposition(-1.0f);
}
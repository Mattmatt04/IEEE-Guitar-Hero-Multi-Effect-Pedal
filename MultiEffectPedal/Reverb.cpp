#include "DaisyDuino.h"
#include "Reverb.h"

void Reverb::Process(float input, float *outL, float *outR) {
  verb.Process(input, input, outL, outR);
}

void Reverb::Initialize(float sample_rate) {
  verb.Init(sample_rate);
  verb.SetFeedback(0.60f);
  verb.SetLpFreq(12000.0f);
}
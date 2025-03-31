#include "DaisyDuino.h"
#include "MatterCompressor.h"

float MatterCompressor::Process(float input) {
  return comp.Process(input);
}

void MatterCompressor::Initialize() {
  comp.SetThreshold(-64.0f); //compresses sound above -64dB
  comp.SetRatio(2.0f); //compression ratio 2:1
  comp.SetAttack(0.005f); 
  comp.SetRelease(0.1250);
}
#include "DaisyDuino.h"
#include "AutoWah.h"

float AutoWah::Process(float input) {
  return wah.Process(input);
}

void AutoWah::Initialize(float sample_rate) {
  wah.Init(sample_rate);
  wah.SetLevel(1);
  wah.SetDryWet(100);
  wah.SetWah(1);
}
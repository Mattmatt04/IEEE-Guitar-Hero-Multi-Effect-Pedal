#include "DaisyDuino.h"
#include "PitchShift.h"

float PitchShift::Process(float input) {
  if(tick.Process()) {
    pitch.SetTransposition(transpose);
    transpose = transpose + 1;

    if(transpose > 20) {
      transpose = 0;
    }
  }

  return pitch.Process(input);
}


void PitchShift::Initialize(float sample_rate) {
  transpose = 0.0;

  pitch.Init(sample_rate);
  pitch.SetTransposition(transpose);
  tick.Init(5.0f, sample_rate);
}

#include "DaisyDuino.h"

class PitchShift {
  public:
    PitchShift() {}
    ~PitchShift() {}

    void Initialize(float sample_rate);
    float Process(float input);

  private:
    PitchShifter pitch;
};
#include "DaisyDuino.h"

class Reverb {
  public:
    Reverb() {}
    ~Reverb() {}

    void Initialize(float sample_rate);
    void Process(float input, float *outL, float *outR);

  private:
    ReverbSc verb;
};
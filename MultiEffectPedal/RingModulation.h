#include "DaisyDuino.h"

class RingModulation {
  public:
    RingModulation() {}
    ~RingModulation() {}

    void Initialize(float sample_rate);
    float Process(float input);

  private:
    Oscillator carrier;
};
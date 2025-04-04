#include "DaisyDuino.h"

#define MAX_DELAY static_cast<size_t>(48000 * 0.75f) // defining MAX_DELAY to 0.75*48000 hz

class USPSDelay {
  public:
    USPSDelay() {}
    ~USPSDelay() {}

    void Initialize(float sample_rate);
    float Process(float input);

  private:
    DelayLine<float, MAX_DELAY> del; // delayline of MAX_DELAY number of floats
    float feedback, del_out, sig_out;
};
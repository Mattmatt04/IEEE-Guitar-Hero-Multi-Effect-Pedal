#include "DaisyDuino.h"

class AntiMatterCompressor {
  public:
    AntiMatterCompressor() {}
    ~AntiMatterCompressor() {}

    float Process(float input);

  private:
    bool bypassHard, bypassSoft;

    float hardClip(float in);
    float softClip(float in);
    float gate(float in);
};
#include "DaisyDuino.h"

class MatterCompressor {
  public:
    MatterCompressor() {}
    ~MatterCompressor() {}

    void Initialize();
    float Process(float input);

  private:
    Compressor comp;
};
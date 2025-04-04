#include "DaisyDuino.h"

class AutoWah {
  public:
    AutoWah() {}
    ~AutoWah() {}

    void Initialize(float sample_rate);
    float Process(float input);

  private:
    Autowah wah; 
};
#include "DaisyDuino.h"

class Lazor{
    public:
        Lazor() {}
        ~Lazor() {}

        void Initialize(float sample_rate, int numFilters);
        float Process(float input);

    private:
        Oscillator lfo;
        float buff[9600];
        int filters;
        size_t size;
        Allpass wire;
};
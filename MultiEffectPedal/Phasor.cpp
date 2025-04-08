#include "DaisyDuino.h"
#include "Phasor.h"

float Lazor::Process(float input) {
    float l = 0.05 + lfo.Process();
    wire.SetFreq(l);
    //float output = input;
    //for(int i = 0; i < filters; i++) {
    //    output = wire.Process(output);
    //}
    float output = wire.Process(input);
    return input + output;
}

void Lazor::Initialize(float sample_rate, int numFilters){
    filters = numFilters; 
    lfo.SetWaveform(lfo.WAVE_SIN);
    lfo.SetFreq(1);
    lfo.SetAmp(0.01);
    for(int i = 0; i < 9600; i++) {
        buff[i] = 0.0f;
    }
    wire.Init(sample_rate, buff, (int)9600);
    
}

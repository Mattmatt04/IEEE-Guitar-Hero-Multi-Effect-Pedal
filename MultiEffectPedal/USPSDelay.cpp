#include "DaisyDuino.h"
#include "USPSDelay.h"

float USPSDelay::Process(float input) {
  del_out = del.Read();
  sig_out = del_out + input;
  feedback = (del_out * 0.5f) + input;

  // Write to the delay
  del.Write(feedback);

  return sig_out;
}

void USPSDelay::Initialize(float sample_rate) {
  del.SetDelay(sample_rate * 0.25f);
}
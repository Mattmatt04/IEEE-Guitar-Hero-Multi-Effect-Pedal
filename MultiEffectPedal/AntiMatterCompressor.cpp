#include "DaisyDuino.h"
#include "AntiMatterCompressor.h"

float AntiMatterCompressor::hardClip(float in) {
  in = in > 1.f ? 1.f : in;
  in = in < -1.f ? -1.f : in;
  return in;
}

float AntiMatterCompressor::softClip(float in) {
  if (in > 0)
    return 1 - expf(-in);
  return -1 + expf(in);
}

float AntiMatterCompressor::gate(float in) {
  if (in > -0.01 && in < 0.01)
    return 0;
  return in;
}

float AntiMatterCompressor::Process(float input) {
  return softClip(1/gate(input));
}
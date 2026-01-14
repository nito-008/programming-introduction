#include <stdio.h>
#include <math.h>

float operation_absdiff(float v1, float v2)
{
  if (v1 > v2)
    return v1 - v2;
  return v2 - v1;
}

float operation_exp(float v1, float v2)
{
  return powf(v1, v2);
}

float operation_log(float v1, float v2)
{
  return logf(v2) / logf(v1);
}
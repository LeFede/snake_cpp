#include <raylib.h>

double lastUpdateTime = 0;

bool interval(double interval)
{
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime < interval) return false;
  lastUpdateTime = currentTime;
  return true;
}

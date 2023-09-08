#include <raymath.h>
#include <deque>
#pragma once

bool element_in_deque(Vector2 element, std::deque<Vector2> deque)
{
  for (auto el : deque) {
    if (Vector2Equals(el, element)) return true;
  }
  return false;
}
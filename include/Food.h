#include <raylib.h>
#include <deque>
#pragma once

class Food 
{
public:
  Vector2 position;
  Food(std::deque<Vector2>);
  void draw() const;
  Vector2 random_pos(std::deque<Vector2>);
};
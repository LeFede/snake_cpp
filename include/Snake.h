#include <raylib.h>
#include <deque>
#pragma once

class Snake 
{

public:
  bool should_add = false;
  Vector2 velocity{1,0};
  std::deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
  Snake();
  void draw() const;
  void update();
};
#include <raylib.h>
#include <deque>
#include "../include/constants.h"
#pragma once

class Snake 
{

public:
  bool should_add = false;
  Vector2 velocity{1,0};
  Vector2 last_velocity;
  std::deque<Vector2> body = constants::INIT_POS;
  Snake();
  void draw() const;
  void reset();
  void update();
};
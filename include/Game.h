#include "../include/Snake.h"
#include "../include/Food.h"
#pragma once

class Game 
{
public:
  double interval = .2;
  Snake snake;
  Food food = Food(snake.body);
  Game();
  void update();
  void draw() const;
  void check_collision_with_food();
};

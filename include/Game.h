#include "../include/Snake.h"
#include "../include/Food.h"
#pragma once

class Game
{
public:
  double interval = .2;
  bool running = true;
  Snake snake;
  Food food = Food(snake.body);
  Game();
  void update();
  void draw() const;
  void check_collision_with_food();
  void check_collision_with_edges();
  void check_collision_with_body();
  void game_over();

};

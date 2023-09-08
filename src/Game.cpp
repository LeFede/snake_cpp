#include "../include/Game.h"
#include <iostream>
#include <raymath.h>
#include "../include/constants.h"

Game::Game()
{

}

void Game::update()
{
  snake.update();
  check_collision_with_food();
}

void Game::draw() const
{
  snake.draw();
  food.draw();
}

void Game::check_collision_with_food() {
  if (Vector2Equals(snake.body[0], food.position))
  {
    food.position = food.random_pos(snake.body);
    snake.should_add = true;
    interval = (interval * .9 > (1 / (double)constants::CELL_AMOUNT)) ? interval * .9 : 1 / (double)constants::CELL_AMOUNT;
    std::cout << interval << std::endl;
  }
}
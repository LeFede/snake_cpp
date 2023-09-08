#include "../include/Game.h"
#include <iostream>
#include <raymath.h>
#include "../include/constants.h"
// #include "../utils/element_in_deque.h"
#include <raymath.h>

bool element_in_dequee(Vector2 element, std::deque<Vector2> deque)
{
  for (auto el : deque) {
    if (Vector2Equals(el, element)) return true;
  }
  return false;
}

Game::Game()
{

}

void Game::update()
{
  if (!running) return;

  snake.update();
  check_collision_with_food();
  check_collision_with_edges();
  check_collision_with_body();
}

void Game::draw() const
{
  snake.draw();
  food.draw();
}

void Game::check_collision_with_food()
{
  if (Vector2Equals(snake.body[0], food.position))
  {
    food.position = food.random_pos(snake.body);
    snake.should_add = true;
    interval = (interval * .9 > (1 / (double)constants::CELL_AMOUNT)) ? interval * .9 : 1 / (double)constants::CELL_AMOUNT;
    std::cout << interval << std::endl;
  }
}

void Game::check_collision_with_edges()
{
  if (snake.body[0].x == constants::CELL_AMOUNT || snake.body[0].x == -1)
  {
    game_over();
  }

  if (snake.body[0].y == constants::CELL_AMOUNT || snake.body[0].y == -1)
  {
    game_over();
  }
}

void Game::check_collision_with_body()
{
  std::deque<Vector2> headlessBody = snake.body;
  headlessBody.pop_front();

  if (element_in_dequee(snake.body[0], headlessBody)) {
    game_over();
  }

  // for (auto segment: snake.body) {
  //   if (Vector2Equals(segment, snake.body[0])) continue;
  //   if (segment.x == snake.body[0].x && segment.y == snake.body[0].y) {
  //     game_over();
  //   }
  // }
}

void Game::game_over()
{
  snake.reset();
  food.position = food.random_pos(snake.body);
  running = false;
  interval = 0.2;
}
#include "../include/Food.h"
#include "../include/constants.h"
// #include "../utils/element_in_deque.h"
#include <raymath.h>
#include <deque>

bool element_in_dequeee(Vector2 element, std::deque<Vector2> deque)
{
  for (auto el : deque) {
    if (Vector2Equals(el, element)) return true;
  }
  return false;
}

Food::Food(std::deque<Vector2> snakeBody) 
{
  position = random_pos(snakeBody);
}

void Food::draw() const 
{
  DrawRectangle(position.x * constants::CELL_SIZE, position.y * constants::CELL_SIZE, constants::CELL_SIZE, constants::CELL_SIZE, constants::SNAKE_COLOR);
}

Vector2 Food::random_pos(std::deque<Vector2> snakeBody) 
{
  float random_x;
  float random_y;

  do 
  {
    random_x = (float)GetRandomValue(0, constants::CELL_AMOUNT - 1);
    random_y = (float)GetRandomValue(0, constants::CELL_AMOUNT - 1);
  } while (element_in_dequeee(Vector2{ random_x, random_y }, snakeBody));

  return Vector2{ random_x, random_y };
}
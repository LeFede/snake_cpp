#include "../include/Snake.h"
#include "../include/constants.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake() {}

void Snake::draw() const 
{
  for (Vector2 segment : body) 
  {
    Rectangle rectangle = Rectangle{ segment.x * constants::CELL_SIZE, segment.y * constants::CELL_SIZE, constants::CELL_SIZE, constants::CELL_SIZE };
    DrawRectangleRounded(rectangle, .5, 6, constants::SNAKE_COLOR);
  }
}

void Snake::update() 
{
  if (should_add) 
  {
    should_add = false;
  } else {
    body.pop_back();
  }
  body.push_front(Vector2Add(body[0], velocity));
}
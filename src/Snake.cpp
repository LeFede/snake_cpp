#include "../include/Snake.h"
#include "../include/constants.h"
#include <raylib.h>
#include <raymath.h>

Snake::Snake() {}

void Snake::draw() const
{
  for (Vector2 segment : body)
  {
    Rectangle rectangle = Rectangle{ constants::OFFSET + segment.x * constants::CELL_SIZE, constants::OFFSET + segment.y * constants::CELL_SIZE, constants::CELL_SIZE, constants::CELL_SIZE };
    DrawRectangleRounded(rectangle, .5, 6, constants::SNAKE_COLOR);
  }
}

void Snake::update()
{
  if (should_add)
  {
    should_add = false;
  }
  else {
    body.pop_back();
  }

  if (last_velocity.x == 1 && velocity.x == -1)
    velocity = { last_velocity.x, velocity.y };

  else if (last_velocity.x == -1 && velocity.x == 1)
    velocity = { last_velocity.x, velocity.y };

  else if (last_velocity.y == 1 && velocity.y == -1)
    velocity = { velocity.x,last_velocity.y };

  else if (last_velocity.y == -1 && velocity.y == 1)
    velocity = { velocity.x, last_velocity.y };

  body.push_front(Vector2Add(body[0], velocity));
  last_velocity = velocity;
}

void Snake::reset()
{
  body = constants::INIT_POS;
  velocity = { 1,0 };
  last_velocity = { 1,0 };
}
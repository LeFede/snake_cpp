#include <raylib.h>
#include <deque>
#pragma once

namespace constants
{
  const int CELL_SIZE{ 16 };
  const int CELL_AMOUNT{ 32 };
  const Color BACKGROUND_COLOR{ 173, 204, 96, 255 };
  const Color SNAKE_COLOR{ 43, 51, 24, 255 };
  const int FPS{ 60 };
  const std::deque<Vector2> INIT_POS{ Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
  const int OFFSET{ 75 };

}
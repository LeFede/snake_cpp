#include <iostream>
#include <raylib.h>
#include <functional>
#include "../include/constants.h"
#include "../utils/interval.h"
#include "../include/Game.h"
#include <raymath.h>

bool element_in_deque(Vector2 element, std::deque<Vector2> deque)
{
  for (auto el : deque) {
    if (Vector2Equals(el, element)) return true;
  }
  return false;
}

int main()
{
  InitWindow(constants::OFFSET * 2 + constants::CELL_SIZE * constants::CELL_AMOUNT, constants::OFFSET * 2 + constants::CELL_SIZE * constants::CELL_AMOUNT, "Snake Game 🦊");
  SetTargetFPS(constants::FPS);

  Game game;

  while (!WindowShouldClose())
  {
    BeginDrawing();

    interval(game.interval) ? game.update() : void();

    switch (GetKeyPressed()) {
    case KEY_W:
      game.snake.velocity = (game.snake.velocity.y != 1) ? Vector2{ 0, -1 } : Vector2{ 0, 1 };
      game.running = true;
      break;

    case KEY_S:
      game.snake.velocity = (game.snake.velocity.y != -1) ? Vector2{ 0, 1 } : Vector2{ 0, -1 };
      game.running = true;
      break;

    case KEY_A:
      game.snake.velocity = (game.snake.velocity.x != 1) ? Vector2{ -1, 0 } : Vector2{ 1,0 };
      game.running = true;
      break;

    case KEY_D:
      game.snake.velocity = (game.snake.velocity.x != -1) ? Vector2{ 1, 0 } : Vector2{ -1, 0 };
      game.running = true;
      break;

    default:
      break;
    }

    ClearBackground(constants::BACKGROUND_COLOR);


    game.draw();

    DrawRectangleLinesEx(Rectangle{ constants::OFFSET - 5, constants::OFFSET - 5, constants::CELL_SIZE * constants::CELL_AMOUNT + 10,  constants::CELL_SIZE * constants::CELL_AMOUNT + 10 }, 5, constants::SNAKE_COLOR);

    DrawText(TextFormat("Score: %i", game.score), constants::OFFSET - 5, 20, 40, constants::SNAKE_COLOR);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}





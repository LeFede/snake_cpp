#include <iostream>
#include <raylib.h>
#include <functional>
#include "../include/constants.h"
#include "../utils/interval.h"
#include "../include/Game.h"

int main()
{
  InitWindow(constants::CELL_SIZE * constants::CELL_AMOUNT, constants::CELL_SIZE * constants::CELL_AMOUNT, "Hello");
  SetTargetFPS(constants::FPS);

  Game game;

  while (!WindowShouldClose()) 
  {
    BeginDrawing();
    ClearBackground(constants::BACKGROUND_COLOR);

    switch (GetKeyPressed()) {
    case KEY_W: game.snake.velocity = (game.snake.velocity.y != 1) ? Vector2{ 0, -1 } : Vector2{ 0, 1 }; break;

    case KEY_S: game.snake.velocity = (game.snake.velocity.y != -1) ? Vector2{ 0, 1 } : Vector2{ 0, -1 }; break;

    case KEY_A: game.snake.velocity = (game.snake.velocity.x != 1) ? Vector2{ -1, 0 } : Vector2{ 1,0 }; break;

    case KEY_D: game.snake.velocity = (game.snake.velocity.x != -1) ? Vector2{ 1, 0 } : Vector2{ -1, 0 }; break;

    default:
      break;
    }

    interval(game.interval) ? game.update() : void();

    game.draw();

    DrawFPS(0, 0);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}





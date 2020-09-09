#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
  : engine(dev()),
    random_w(0, static_cast<int>(grid_width)),
    random_h(0, static_cast<int>(grid_height)) {
  std::shared_ptr<Snake> snake_left = std::make_shared<Snake>(grid_width, grid_height, 0);
  std::shared_ptr<Snake> snake_right = std::make_shared<Snake>(grid_width, grid_height, 1);
  snakes_.push_back(snake_left);
  snakes_.push_back(snake_right);
  for (int i = 0; i < food_size; ++i) {
    SDL_Point food;
    PlaceFood(food);
    foods.emplace_back(food);
  }

  for (int i = 0; i < poison_size; ++i) {
    SDL_Point poison;
    PlacePoison(poison);
    poisons.emplace_back(poison);
  }
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snakes_);
    Update();
    renderer.Render(snakes_, foods, poisons);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score_left, score_right, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood(SDL_Point &food) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    bool is_Occupied = false;
    for (auto const snake : snakes_) {
      if (snake->SnakeCell(x, y)) {
        is_Occupied = true;
        break;
      }
    }
    if (is_Occupied) {
      continue;
    }

    food.x = x;
    food.y = y;
    return;
  }
}

void Game::PlacePoison(SDL_Point &poison) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing food.
    bool is_Occupied = false;
    for (auto const snake : snakes_) {
      if (snake->SnakeCell(x, y)) {
        is_Occupied = true;
        break;
      }
    }
    if (is_Occupied) {
      continue;
    }

    poison.x = x;
    poison.y = y;
    return;
  }
}

void Game::Update() {
  for (int i = 0; i < 2; ++i) { // left or right snake
    auto &snake = snakes_[i];
    if (!snake->alive) return;

    snake->Update();
    int new_x = static_cast<int>(snake->head_x);
    int new_y = static_cast<int>(snake->head_y);

    // Check if there's food over here
    for (auto &food : foods) {
      if (food.x == new_x && food.y == new_y) {
        if (snake->GetSnakeId() == 0) score_left++;
        if (snake->GetSnakeId() == 1) score_right++;
        PlaceFood(food);
        // Grow snake and increase speed.
        snake->GrowBody();
        snake->speed += 0.01;
      }
    }

    // Check if snakes hit poisons
    for (auto &poison : poisons) {
      if (poison.x == new_x && poison.y == new_y) {
        if (snake->GetSnakeId() == 0) {
          left_alive = false;
          std::cout << "============================================" << std::endl;
          std::cout << "  Left Snake ate poison, Gamer Over!" << std::endl;
          std::cout << "============================================" << std::endl;
        }
        if (snake->GetSnakeId() == 1) {
          right_alive = false;
          std::cout << "============================================" << std::endl;
          std::cout << "  Right Snake ate poison, Gamer Over!" << std::endl;
          std::cout << "============================================" << std::endl;
        }
        snakes_[0]->alive = false;
        snakes_[1]->alive = false;
        return;
      }
    }
  }
}

int Game::GetLeftScore() const { return score_left; }

int Game::GetLeftSize() const { return snakes_[0]->size; }

int Game::GetRightScore() const { return score_right; }

int Game::GetRightSize() const { return snakes_[1]->size; }

bool Game::GetLeftStatus() const { return left_alive; }

bool Game::GetRightStatus() const { return right_alive; }
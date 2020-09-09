/*******************************************************************************
@file: game.h

@brief - header for games main running loop
*******************************************************************************/
#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
/* CLASS DECLARATION **********************************************************/
public:
  /**
   * Function to create snakes, food and poison in the game
   * @param grid_width
   * @param grid_height
   */
  Game(std::size_t grid_width, std::size_t grid_height);

  /**
   * Function to start the game loop
   * @param controller
   * @param renderer
   * @param target_frame_duration
   */
  void Run(SDL::Controller const &controller, SDL::Renderer &renderer,
           std::size_t target_frame_duration);

  /**
   * Getter for score of the left snake
   * @return integer for score
   */
  int GetLeftScore() const;

  /**
   * Getter for size of the left snake
   * @return integer for size of the snake
   */
  int GetLeftSize() const;

  /**
   * Getter for the right snake's score
   * @return integer for right score
   */
  int GetRightScore() const;

  /**
   * Getter for the size of the right snake
   * @return integer for right snake's size
   */
  int GetRightSize() const;

  /**
   * Getter for the status for left snake
   * @return True for alive, otherwise false
   */
  bool GetLeftStatus() const;

  /**
   * Getter for the state of the right snake
   * @return True for alive, otherwise false
   */
  bool GetRightStatus() const;

private:
  /**
   * Function to place food on the board at places where snake's body is absent
   * @param food
   */
  void PlaceFood(SDL_Point &food);

  /**
   * Function to place poison on the board where snake's body is not present
   * @param poison
   */
  void PlacePoison(SDL_Point &poison);

  /**
   * Update the status of the snake
   */
  void Update();

  std::vector<std::shared_ptr<Capstone::Snake>> snakes_;
  std::vector<SDL_Point> foods;
  const int food_size = 5;
  std::vector<SDL_Point> poisons;
  const int poison_size = 3;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score_left{0};
  int score_right{0};

  bool left_alive = true;
  bool right_alive = true;


};

#endif
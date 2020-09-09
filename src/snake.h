/*******************************************************************************
@file: snake.h

@brief - header for Snake class
*******************************************************************************/
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <memory>
#include "SDL.h"

namespace Capstone {
class Snake {
/* CLASS DECLARATION **********************************************************/

public:
  enum class Direction {
    kUp, kDown, kLeft, kRight
  };
  /**
   * Constructor for the class which contains attributes to keep track
   * of the Snake speed, size, and location, and ID
   * @param grid_width
   * @param grid_height
   * @param id
   */
  Snake(int grid_width, int grid_height, int id)
    : grid_width(grid_width),
      grid_height(grid_height),
      head_x(grid_width / 2),
      head_y(grid_height / 2),
      snake_id_(id) {}
  /**
   * Function to update snake's state
   */
  void Update();

  /**
   * Function to grow snake's body
   */
  void GrowBody();

  /**
   * Function to tell if a set of x-y values has snake's body
   * @param x
   * @param y
   * @return
   */
  bool SnakeCell(int x, int y);

  /**
   * Getter for snake id
   * @return
   */
  int GetSnakeId() const;

  Direction direction = Direction(rand() % 4);

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

private:
  /**
   * Function to update snake's head position
   */
  void UpdateHead();

  /**
   * Function to update Snake's body
   * @param current_cell
   * @param prev_cell
   */
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  int snake_id_;
};
}

#endif
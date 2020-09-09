/*******************************************************************************
@file: renderer.h

@brief - header for SDL render
*******************************************************************************/
#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

namespace SDL {

class Renderer {
/* CLASS DECLARATION **********************************************************/
public:
  /**
   * class constructor that creates the SDL window
   * @param screen_width
   * @param screen_height
   * @param grid_width
   * @param grid_height
   */
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);

  ~Renderer();

  /**
   * Function that draws the food and the snake in the window using
   * the SDL renderer.
   * @param snakes
   * @param foods
   * @param poisons
   */
  void Render(const std::vector<std::shared_ptr<Capstone::Snake>> &snakes,
              const std::vector<SDL_Point> &foods,
              const std::vector<SDL_Point> &poisons);

  /**
   * Updates the score and FPS on the top
   * @param score_left
   * @param score_right
   * @param fps
   */
  void UpdateWindowTitle(int score_left, int score_right, int fps);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};
}
#endif
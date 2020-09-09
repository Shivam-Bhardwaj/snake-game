/*******************************************************************************
@file: controller.h

@brief - header for game's controller class that takes in input from user
*******************************************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

namespace SDL {
/* CLASS DECLARATION **********************************************************/
class Controller {
public:
  /**
   * Function that takes in Input
   * @param running: bool that stores the state of the game
   * @param snakes
   */
  void HandleInput(bool &running,
                   std::vector<std::shared_ptr<Capstone::Snake>> &snakes) const;

private:
  /**
   * Function to change direction of the snake based on the keyboard input
   * @param snake
   * @param input
   * @param opposite
   */
  void ChangeDirection(std::shared_ptr<Capstone::Snake> snake,
                       Capstone::Snake::Direction input,
                       Capstone::Snake::Direction opposite) const;
};
}
#endif
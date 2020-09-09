#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

namespace SDL {
  class Controller {
  public:
    void HandleInput(bool &running, std::vector<std::shared_ptr<Capstone::Snake>> &snakes) const;

  private:
    void ChangeDirection(std::shared_ptr<Capstone::Snake> snake, Capstone::Snake::Direction input,
                         Capstone::Snake::Direction opposite) const;
  };
}
#endif
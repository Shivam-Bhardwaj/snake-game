# Capstone Snake Game

![image](README.assets/screenshot.jpg)

The Capstone Project of Udacity's C++ NanoDegree is a modified version of the boilerplate game given to the students.

In the current version, a second snake is added to make the game multi-player. In addition to this poison is added to kill the snake that touches it.

## Project structure

```bash
project_folder
├── src  # Contain the main source files of the project 
│   ├── main.cpp # The main file used to compile the project
│   ├── snake.h # Header for snake class
│   ├── snake.cpp # Functions for class that create snake's behaviour
│   ├── controller.h # Class that helps to capture user input
│   ├── controller.cpp # Contains functions for controller class
│   ├── game.h # Game class that helps to run the main game loop
│   ├── game.cpp # Functions for game class
│   ├── renderer.h # Contains defines class for SDL renderer
│   └── renderer.cpp # Function definitions for renderer class
├── CMakeLists.txt # CMakeList for compiling the project
├── cmake # Folder that contains file(s)
│   └── FindSDL2_image.cmake # cmake file for proper linking of SDL library to the project
├── README.assets # Contains necessary filed for README.md 
├── README.md # The markdown file for explanation of the project
```



## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Project Rubrics Discussed

In order to have a successful submission, we are supposed to address at least 5 optional rubrics given in the capstone project. 

| Category/Rubric                                              | Explanation and link(s)                                      |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Loops, Functions, I/O**<br />The project demonstrates an understanding of C++ functions and control structures. | The whole project is organized with proper use of functions and flow of data. |
| **Object Oriented Programming**<br />The project uses Object Oriented Programming techniques. | As mentioned in the project structure the code uses 4 classes : [Snake](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h), [Controller](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/controller.h), [Game](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h) and [Renderer](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h) class. All the data and the control logic is encapsulated in them. |
| **Object Oriented Programming**<br />Classes use appropriate access specifiers for class members. | In all the classes mentioned above, the data and member functions under private or public access specifiers based on the usability outside the class. Example the *getters* (ex [int GetSnakeId()](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h#L56)) are put in public, but the *Update*(ex [void UpdateBody()](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h#L78)) functions are put in in private as they are supposed to used from the class's member functions only. |
| **Object Oriented Programming**<br />Class constructors utilize member initialization lists. | Several functions ex: [Snake constructor](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h#L28) uses member initializer lists. |
| **Object Oriented Programming**<br />Classes abstract implementation details from their interfaces. | All the header files contains proper documentation of the member functions ex: [link](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/snake.h#L39) |
| **Memory Management**<br />The project makes use of references in function declarations. | [link1: ](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h#L39) void Render() and [link2:](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h#L83) void PlacePoison() uses pass by reference |
| **Memory Management**<br />The project uses smart pointers instead of raw pointers. | To create multiple snakes I have used a vector of shared pointers [ex](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/game.h#L90) |
| **Memory Management**<br />The project uses destructor(s) appropriately. | Destructor for [renderer](https://github.com/Shivam-Bhardwaj/snake-game/blob/master/src/renderer.h#L28) is used to close the window and perform cleanup after the game ends |


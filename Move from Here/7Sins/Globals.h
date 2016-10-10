#ifndef GLOBALS_H
#define GLOBALS_H

//pre-defined headers
#include "Dependencies\Include\SFML\Graphics.hpp"
#include <SFML/Audio.hpp>
static const int SCREEN_WIDTH = 1024;
static const int SCREEN_HEIGHT = 768;
static const int SCREEN_BPP = 32;
static const int gameTime = 10;
static const int RATIO = 30;
#define UNRATIO (1.0F/RATIO)
extern sf::RenderWindow App;

#endif
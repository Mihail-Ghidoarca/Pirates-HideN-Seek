#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <stdio.h>

extern sf::RenderWindow renderWindow;
extern sf::Sound click;
extern bool SFX;
extern bool Music;
extern int vStele[31];
int Play(int niv);
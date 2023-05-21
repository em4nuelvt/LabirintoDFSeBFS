#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "maze.hpp"

void generateNextMove(unsigned int movementCase, unsigned int* currentX, unsigned int* currentY);
void startRandom();
unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols);

#endif
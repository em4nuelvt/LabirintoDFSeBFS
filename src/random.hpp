#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "maze.hpp"

void generateNextMove(unsigned int movementCase, unsigned int* currentX, unsigned int* currentY);
void startRandom(int* iteracoes,string* exibe, int escolha,ofstream &outFile);
unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols);
void writeOutputRND(char** matrix, unsigned int nRows, unsigned int nCols,ofstream &outFile);
#endif
#ifndef MAZE_HPP
#define MAZE_HPP
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;

char** allocateMatrix( unsigned int nRows,  unsigned int nCols);
char** readMatrix(char** matrix, unsigned int nRows, unsigned int nCols, ifstream &inFile);
void freeMatrix(char**matrixMaze, unsigned int nRows);
unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols);
void moveLeft(unsigned int* x, unsigned int* y);
void moveRight(unsigned int* x, unsigned int* y);
void moveUp(unsigned int* x, unsigned int* y);
void moveDown(unsigned int* x, unsigned int* y);
void generateNextMove(unsigned int movementCase, unsigned int* currentX, unsigned int* currentY);
void printMatrix(char** matrix, unsigned int nRows, unsigned int nCols);
void printMatrixWithColor(char** matrixMaze,unsigned int nRows, unsigned int nCols,unsigned int x, unsigned int y);
void startRandom();


#endif
#ifndef BFS_HPP
#define BFS_HPP
#include "fila.hpp"
#include <cstring>
#include "maze.hpp"

void startBfs();
bool isValidPosition(unsigned int x, unsigned int y, unsigned int nRows, unsigned int nCols);
Position bfs(char** matrix, Position start, unsigned int nRows, unsigned int nCols );
void printMatrixBfs(char** matrix,unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols, bool** visitedPositions);
#endif
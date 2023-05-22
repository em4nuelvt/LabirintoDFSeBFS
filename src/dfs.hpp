#ifndef DFS_HPP
#define DFS_HPP
#include "pilha.hpp"
#include <cstring>
#include "maze.hpp"

void startDfs();
bool isValidPosition(unsigned int x, unsigned int y, unsigned int nRows, unsigned int nCols);
Position dfs(char** matrix, Position start, unsigned int nRows, unsigned int nCols );
void printMatrixDfs(char** matrix, unsigned int nRows, unsigned int nCols, bool** visitedPositions);
#endif
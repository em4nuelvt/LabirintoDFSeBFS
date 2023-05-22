#ifndef DFS_HPP
#define DFS_HPP
#include "pilha.hpp"
#include "bfs.hpp"
#include <cstring>
#include "maze.hpp"

void startDfs();
bool isValidPosition(int x, int y, int nRows, int nCols);
Position dfs(char** matrix, Position start, int nRows, int nCols );
void printMatrixDfs(char** matrix,int currentX, int currentY, int nRows, int nCols, bool** visitedPositions);
#endif
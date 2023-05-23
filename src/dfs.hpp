#ifndef DFS_HPP
#define DFS_HPP
#include "pilha.hpp"
#include "bfs.hpp"
#include <cstring>
#include "maze.hpp"

void startDfs(int* iteracoes, string* exibe, int escolha,ofstream &outFile);
bool isValidPosition(int x, int y, int nRows, int nCols);
void writeOutputDfs(char** matrix, int nRows, int nCols, bool** visitedPositions, ofstream &outputFile);
Position dfs(char** matrix, Position start, int nRows, int nCols,int* iteracoes, int escolha,ofstream &outFile);
void printMatrixDfs(char** matrix,int currentX, int currentY, int nRows, int nCols, bool** visitedPositions);
#endif
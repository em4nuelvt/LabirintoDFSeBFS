#ifndef BFS_HPP
#define BFS_HPP
#include "fila.hpp"
#include <cstring>
#include "maze.hpp"

void startBfs(int* iteracoes,string* exibe,int escolha,ofstream &outFile);
bool isValidPosition(int x, int y, int nRows, int nCols);
void writeOutputBfs(char** matrix, int nRows, int nCols, bool** visitedPositions, ofstream &outputFile);
Position bfs(char** matrix, Position start, int nRows, int nCols,int* iteracoes, int escolha,ofstream &outFile);
void printMatrixBfs(char** matrix,int currentX, int currentY, int nRows, int nCols, bool** visitedPositions);
#endif
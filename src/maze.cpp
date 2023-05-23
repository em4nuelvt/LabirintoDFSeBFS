#include "maze.hpp"
void moveLeft(unsigned int* x, unsigned int* y){
    *y=*y-1;
}
void moveRight(unsigned int* x, unsigned int* y){
    *y=*y+1;
}
void moveUp(unsigned int* x, unsigned int* y){
    *x=*x-1;
}
void moveDown(unsigned int* x, unsigned int* y){
    *x=*x+1;
}

char** allocateMatrix( unsigned int nRows,  unsigned int nCols){
    char** matrixMaze;
    matrixMaze= (char**)malloc(sizeof(char*)*nRows);
    for(unsigned int i=0;i<nRows;i++){
        matrixMaze[i]=(char*) malloc(sizeof(char)*nCols);
    }
    return matrixMaze;
}

void freeMatrix(char**matrixMaze, unsigned int nRows){
    for(unsigned int i=0;i<nRows;i++){
        free(matrixMaze[i]);
    }
    free(matrixMaze);
}

char** readMatrix(char** matrix,unsigned int nRows, unsigned int nCols, ifstream &inFile){
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            inFile>>matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(char** matrix, unsigned int nRows, unsigned int nCols){
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            cout<<"["<<matrix[i][j]<<"] ";
        }
        cout<<endl;
    }
}

void printMatrixWithColor(char** matrixMaze,unsigned int nRows, unsigned int nCols,unsigned int x, unsigned int y){
    std::cout << "\033[31m"; // define a cor vermelha
    std::cout <<"Busca randomica "<<endl<<endl;
    std::cout << "\033[0m"; // restaura a cor padrão
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            if((i==x)&&(j==y)){
                std::cout << "\033[31m"; // define a cor vermelha
                std::cout <<"["<<matrixMaze[i][j]<<"] ";
                std::cout << "\033[0m"; // restaura a cor padrão
            }else{
                cout<<"["<<matrixMaze[i][j]<<"] ";
            }
        }
        cout<<endl;
    }
}

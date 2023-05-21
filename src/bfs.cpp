#include "bfs.hpp"

void startBfs(){
    char** matrix;
    unsigned int nRows,nCols;
    ifstream inFile;
    inFile.open("dataset/input.data",std::ios::in);
    if(!inFile){
        cerr<<"Não foi possível abrir o arquivo!"<<endl;
        return ;
    }
    inFile>>nRows>>nCols;
    matrix=allocateMatrix(nRows,nCols);
    readMatrix(matrix,nRows,nCols,inFile);
    Position start = {0,0};
    Position result = bfs (matrix,start,nRows,nCols);
    if (result.row == -1 && result.col == -1) {
        cout << "Posição não encontrada."<<endl;
    } else {
        cout << "Posição encontrada: (" << result.row << ", " << result.col << ")"<<endl;
    }

    freeMatrix(matrix,nRows);    
}

bool isValidPosition(unsigned int x, unsigned int y, unsigned int nRows, unsigned int nCols){
    return(x>=0 && x<nRows && y>=0 && y<nCols);
}

void printMatrixBfs(char** matrix, unsigned int nRows, unsigned int nCols, bool** visitedPositions){
    std::cout << "\033[32m"; // define a cor vermelha
    std::cout<<"Busca em largura:"<<endl<<endl;
    std::cout << "\033[0m"; // restaura a cor padrão
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            if(visitedPositions[i][j]){
                cout<<"[x] ";
            }else{
                cout<<"["<<matrix[i][j]<<"] ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}


Position bfs(char** matrix, Position start, unsigned int nRows, unsigned int nCols ){
    // Matriz para marcar as posições já visitadas
    bool **visitedPositions= (bool**)(malloc(sizeof(bool*)*nRows));
    for (unsigned int i=0;i<nRows;i++){
        visitedPositions[i]=(bool*)(malloc(sizeof(bool)*nCols));
    }
    for(unsigned int i=0;i<nRows;i++){
        for(unsigned int j=0;j<nCols;j++){
            visitedPositions[i][j]=false;
        }
    }
    //Fila para armazenar as posições a serem visitadas
    Fila fila;

    //insere a posição inicial na fila
    fila.empilhar(start);
    visitedPositions[start.row][start.col]=true;

    //vetores de direções de movimentação (cima,baixo,direita,esquerda)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!fila.vazia()){
        //obtem a posição atual da fila
        Position current = fila.desempilhar();

        //verifica se a posição atual possui o caractere desejado
        if (matrix[current.row][current.col] == '?') {
            return current;
        }

        if (matrix[current.row][current.col] == '*') {
            cout<<"caractere * encontrado, reinicia busca"<<endl;
            while (!fila.vazia()) {
                fila.desempilhar();
            }
            fila.empilhar(start);
            for(unsigned int i=0;i<nRows;i++){
                for(unsigned int j=0;j<nCols;j++){
                    visitedPositions[i][j]=false;
                }
            }
            visitedPositions[start.row][start.col] = true;
            matrix[current.row][current.col]='1';
            continue;
        }
        //percorrer todas as possiveis movimentações da posição atual
        //para colocar novas posições na fila
        for (unsigned int i = 0; i < 4; i++) {
            unsigned int newRow = current.row + dr[i];
            unsigned int newCol = current.col + dc[i];

            //verifica se a posição é válida
            //- diferente de parede
            //- não excede o limite da matriz
            //- não foi visitada
            if (isValidPosition(newRow, newCol,nRows,nCols) && !visitedPositions[newRow][newCol] && matrix[newRow][newCol] != '#') {
                visitedPositions[newRow][newCol] = true;
                Position newPosition = {newRow, newCol};
                fila.empilhar(newPosition);
            }
        }
        printMatrixBfs(matrix,nRows,nCols,visitedPositions);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        system("clear");        
    }
    return{0,0};


}
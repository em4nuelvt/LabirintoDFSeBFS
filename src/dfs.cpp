#include "bfs.hpp"
#include "dfs.hpp"
void startDfs(){
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
    Position result = dfs(matrix,start,nRows,nCols);
    cout << "Posição encontrada: (" << result.row << ", " << result.col << ")"<<endl;


    freeMatrix(matrix,nRows);    
}


void printMatrixDfs(char** matrix, unsigned int nRows, unsigned int nCols, bool** visitedPositions){
    std::cout << "\033[32m"; // define a cor vermelha
    std::cout<<"Busca em profundidade:"<<endl<<endl;
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


Position dfs(char** matrix, Position start, unsigned int nRows, unsigned int nCols ){
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
    Pilha fila;

    //insere a posição inicial na fila
    fila.empilhar(start);
    visitedPositions[start.row][start.col]=true;

    //vetores de direções de movimentação (baixo,direita,cima,esquerda)
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!fila.vazia()){
        //obtem a posição atual da fila
        Position current = fila.desempilhar();
        visitedPositions[current.row][current.col] = true;

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
        //para colocar novas posições na pilha
        for (int i = 3; i >= 0; i--){
            unsigned int newRow = current.row + dr[i];
            unsigned int newCol = current.col + dc[i];

            //verifica se a posição é válida
            //- diferente de parede
            //- não excede o limite da matriz
            //- não foi visitada
            if (isValidPosition(newRow, newCol,nRows,nCols) && !visitedPositions[newRow][newCol] && matrix[newRow][newCol] != '#') {
                //visitedPositions[newRow][newCol] = true;
                Position newPosition = {newRow, newCol};
                fila.empilhar(newPosition);
            }
        }
        /* Position neighbors[4] = {{current.row - 1, current.col}, {current.row + 1, current.col}, {current.row, current.col - 1}, {current.row, current.col + 1}};
        for (int i = 3; i >= 0; i--) {
            int newRow = neighbors[i].row;
            int newCol = neighbors[i].col;

            if (isValidPosition(newRow, newCol,nRows,nCols) && !visitedPositions[newRow][newCol] && matrix[newRow][newCol] != '#') {
                fila.empilhar(neighbors[i]);
            }
        } */
        printMatrixDfs(matrix,nRows,nCols,visitedPositions);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        system("clear");        
    }
    return{0,0};


}
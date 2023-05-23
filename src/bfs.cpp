#include "bfs.hpp"

void startBfs(int* iteracoes, string* exibe,int escolha,ofstream &outFile){

    char** matrix;
    int nRows,nCols;
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
    Position result = bfs (matrix,start,nRows,nCols,iteracoes,escolha,outFile);
    cout << "Posição encontrada(bfs): (" << result.row << ", " << result.col << ")"<<endl;
    *exibe= *exibe + "Posição encontrada (bfs): ("+ to_string(result.row) +", "+to_string(result.col)+") "+to_string(*iteracoes)+" iterações\n";
    freeMatrix(matrix,nRows);    
}

bool isValidPosition(int x, int y, int nRows, int nCols){
    return(x>=0 && x<nRows && y>=0 && y<nCols);
}
void printMatrixBfs(char** matrix,int currentX, int currentY, int nRows, int nCols, bool** visitedPositions){
    std::cout << "\033[32m"; // define a cor vermelha
    std::cout<<"Busca em largura:"<<endl<<endl;
    std::cout << "\033[0m"; // restaura a cor padrão
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
            if((i==currentX)&&(j==currentY)){
                std::cout << "\033[32m"; // define a cor vermelha
            }
            if(visitedPositions[i][j]){
                cout<<"[x] ";
            }else{
                cout<<"["<<matrix[i][j]<<"] ";
            }
            std::cout << "\033[0m"; // restaura a cor padrão
        }
        cout<<endl;
    }
    cout<<endl;
}

void writeOutputBfs(char** matrix, int nRows, int nCols, bool** visitedPositions, ofstream &outputFile){
    outputFile<<"Matriz BFS:"<<endl;
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){

            if(visitedPositions[i][j]){
                outputFile<<"[x] ";
            }else{
                outputFile<<"["<<matrix[i][j]<<"] ";
            }
        }
        outputFile<<endl;
    }
    outputFile<<endl<<endl;
}


Position bfs(char** matrix, Position start, int nRows, int nCols,int* iteracoes,int escolha,ofstream &outFile){
    // Matriz para marcar as posições já visitadas
    bool **visitedPositions= (bool**)(malloc(sizeof(bool*)*nRows));
    for (int i=0;i<nRows;i++){
        visitedPositions[i]=(bool*)(malloc(sizeof(bool)*nCols));
    }
    for(int i=0;i<nRows;i++){
        for(int j=0;j<nCols;j++){
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

        *iteracoes=*iteracoes+1;

        //obtem a posição atual da fila
        Position current = fila.desempilhar();

        //verifica se a posição atual possui o caractere desejado
        if (matrix[current.row][current.col] == '?') {
            writeOutputBfs(matrix,nRows,nCols,visitedPositions,outFile);
            return current;
        }

        if (matrix[current.row][current.col] == '*') {
            cout<<"caractere * encontrado, reinicia busca"<<endl;
            while (!fila.vazia()) {
                fila.desempilhar();
            }
            fila.empilhar(start);
            for(int i=0;i<nRows;i++){
                for(int j=0;j<nCols;j++){
                    visitedPositions[i][j]=false;
                }
            }
            visitedPositions[start.row][start.col] = true;
            matrix[current.row][current.col]='1';
            continue;
        }
        //percorrer todas as possiveis movimentações da posição atual
        //para colocar novas posições na fila
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

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
        if(escolha==1){
            printMatrixBfs(matrix,current.row, current.col,nRows,nCols,visitedPositions);
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            system("clear");
        }        
    }
    return{-1,-1};


}
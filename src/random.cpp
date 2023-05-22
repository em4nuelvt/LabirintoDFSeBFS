#include "random.hpp"

unsigned int getMovementCase(unsigned int currentX, unsigned int currentY, unsigned int nRows, unsigned int nCols){
    /*Legenda de movimentos: 
    1- Vertice superior esquerdo - 2 possíveis movimentos
    2- Vertice superior direito - 2 movimentos
    3- Vertice inferior esquerdo - 2 movimentos
    4- Vertice inferior direito - 2 movimentos
    5- Primeira Linha - 3 moimentos
    6- Primeira Coluna - 3 movimentos
    7- Ultima linha - 3 movimentos
    8- Ultima coluna - 3 movimentos
    9- Meio da matriz - 4 movimentos */
    if(currentX==0 && currentY==0){
        return 1;
    } else if((currentX==0) && (currentY==nCols-1)){
        return 2;
    }else if( (currentX==(nRows-1)) && (currentY==0) ){
        return 3;
    }else if((currentX==(nRows-1))&& ( currentY==(nCols-1) ) ){
        return 4;
    }else if(currentX==0){
        return 5;
    }else if(currentY==0){
        return 6;
    }else if(currentX==(nRows-1)){
        return 7;
    }else if(currentY==(nCols-1)){
        return 8;
    }else{
        return 9;
    }
}
void generateNextMove(unsigned int movementCase, unsigned int* currentX, unsigned int* currentY){
    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> dist1(1, 2);
    uniform_int_distribution<int> dist2(1, 3);
    uniform_int_distribution<int> dist3(1, 4);

    unsigned int random1=dist1(rng);
    unsigned int random2=dist2(rng);
    unsigned int random3=dist3(rng);

    switch (movementCase)
    {
    case 1:
        if(random1==1){
            cout<<"Movimenta Direita"<<endl;
            moveRight(currentX, currentY);
        }else {
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }
        break;
    case 2:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else{
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }break;

    case 3:
        if(random1==1){
            cout<<"Movimenta Direita"<<endl;
            moveRight(currentX, currentY);
        }else{
            cout<<"Movimenta Cima"<<endl;
            moveUp(currentX, currentY);
        }
        break;
    case 4:
        if(random1==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else{
            cout<<"Movimenta Cima"<<endl;
            moveUp(currentX, currentY);
        }
        break;
    case 5:
        if(random2==1){
            cout<<"Movimenta Esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta Baixo"<<endl;
            moveDown(currentX, currentY);
        }else{
            cout<<"Movimenta Direita"<<endl;
            moveRight(currentX, currentY);
        }
        break;
    case 6:
        if(random2==1){
            cout<<"Movimenta cima "<<endl;
            moveUp(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }else{
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }
        break;
    case 7:
        if(random2==1){
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);
        }else{
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }
        break;
    case 8:
        if(random2==1){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);
        }else if(random2==2){
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }else{
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }
        break;
    case 9:
        if(random3==1){
            cout<<"Movimenta cima"<<endl;
            moveUp(currentX, currentY);

        }else if(random3==2){
            cout<<"Movimenta direita"<<endl;
            moveRight(currentX, currentY);
        }else if(random3==3){
            cout<<"Movimenta baixo"<<endl;
            moveDown(currentX, currentY);
        }else{
            cout<<"Movimenta esquerda"<<endl;
            moveLeft(currentX, currentY);
        }
        break;
    }
}

void startRandom(){
    char** matrix;
    unsigned int movementCase;
    unsigned int currentX=0, currentY=6, lastY=currentY, lastX=currentX;
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
    cout<<endl;
    while(1){
        //////////////////////imprimir//////////////////////////////// 
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        std::system("clear"); 
        // Imprime uma nova saída
        printMatrixWithColor(matrix,nRows,nCols,currentX,currentY);
        cout<<"Position: ("<<currentX<<","<<currentY<<")"<<endl;
        // Aguarda 0,1 segundos
        std::this_thread::sleep_for(std::chrono::milliseconds(30));

        ///////////////////////movimentar//////////////////////////////
        lastX=currentX,lastY=currentY;
        movementCase=getMovementCase(currentX,currentY,nRows,nCols);
        generateNextMove(movementCase,&currentX,&currentY);
        do{//tratando as paredes
            if(matrix[currentX][currentY]=='#'){
                currentX=lastX, currentY=lastY;
                movementCase=getMovementCase(currentX,currentY,nRows,nCols);
                generateNextMove(movementCase,&currentX,&currentY);
            }
        }while(matrix[currentX][currentY]=='#');
        //////////////////////////////////////////////////////////////
        ///////////////// tratamento de itens da matriz///////////////
        if(matrix[currentX][currentY]=='?'){
            cout<<"achou o objetivo"<<endl;
            break;
        }
        else if(matrix[currentX][currentY]=='*'){
            cout<<"Volta para o começo"<<endl;
            matrix[currentX][currentY]='1';
            currentX=0;
            currentY=0;
        }else{
            matrix[currentX][currentY]='x';
        }

    }

    /* cout<<nRows<<endl<<nCols<<endl; */
    freeMatrix(matrix,nRows);
}

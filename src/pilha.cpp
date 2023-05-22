#include "pilha.hpp"

Pilha::Pilha(){
    topo=NULL;
}

Pilha::~Pilha(){
    while(!vazia()){
        desempilhar();
    }
}

bool Pilha::vazia(){
    return topo==NULL;
}

void Pilha::empilhar(Position value){
    No* novo = new No;
    novo->data=value;
    novo->prox=topo;
    topo=novo;
}

Position Pilha::desempilhar(){
    if(vazia()){
        cout<<"A fila está vazia."<<endl;
        return {0,0};
    }

    No* temp = topo;
    Position value= temp->data;
    topo=topo->prox;

    delete temp;
    return value;
}
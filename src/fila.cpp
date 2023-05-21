#include "fila.hpp"

Fila::Fila(){
    primeiro=NULL;
    ultimo=NULL;
}

Fila::~Fila(){
    while(!vazia()){
        desempilhar();
    }
}

bool Fila::vazia(){
    return primeiro==NULL;
}

void Fila::empilhar(Position value){
    Node* novo = new Node;
    novo->data=value;
    novo->prox=NULL;
    if (vazia()){
        primeiro=novo;
        ultimo=primeiro;
    }else{
        ultimo->prox=novo;
        ultimo=novo;
    }
}

Position Fila::desempilhar(){
    if(vazia()){
        cout<<"A fila está vazia."<<endl;
        return {0,0};
    }

    Node* temp = primeiro;
    Position value= temp->data;

    if(primeiro==ultimo){
        primeiro=NULL;
        ultimo=primeiro;
    }else{
        primeiro=primeiro->prox;
    }
    delete temp;
    return value;
}
#ifndef FILA_HPP
#define FILA_HPP
#include <iostream>
#include <cstring>
using namespace std;

struct Position{
    unsigned int row;
    unsigned int col;
};

struct Node {
    Position data;
    Node *prox;
};

class Fila{
    private:
       Node* primeiro;
       Node* ultimo;
    public:
        Fila();
        ~Fila(); 
        bool vazia();
        void empilhar(Position value);
        Position desempilhar();

};



#endif
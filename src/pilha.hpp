#ifndef PILHA_HPP
#define PILHA_HPP
#include "fila.hpp"
#include <iostream>
#include <cstring>
using namespace std;


struct No{
    Position data;
    No *prox;
};

class Pilha{
    private:
       No* topo;
    public:
        Pilha();
        ~Pilha(); 
        bool vazia();
        void empilhar(Position value);
        Position desempilhar();

};



#endif
#ifndef TESTAORDENA_H
#define TESTAORDENA_H

#include"Item.h"
#include<iostream>
#include<random>

using namespace std;

class TestaOrdena
{
    int tam;
    Item **vetor;

    void print(int, int, char**);
public:
    TestaOrdena();
    bool setTam(int);
    int getTam() const;
    void preencheVetor();
    void mostraVetor(Item ** aux);
    Item ** copiaVetor();
    void menu();
};

#endif // TESTAORDENA_H

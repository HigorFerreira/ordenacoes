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
public:
    TestaOrdena();
    Item ** getVetor();
    bool setTam(int);
    int getTam() const;
    void preencheVetor();
    void mostraVetor(Item ** aux);
    void copiaVetor(Item ** copia);
    void menu();
};

#endif // TESTAORDENA_H

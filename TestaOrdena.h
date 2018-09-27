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

    void insertion(int);
    void selection(int);
    void merge(int);
    void shell(int);
    void bubble(int);
    void heap(int);
    void quick(int);
    void callAll(int);
public:
    TestaOrdena();
    Item **getVector();
    bool setTam(int);
    int getTam() const;
    void preencheVetor();
    void mostraVetor(Item ** aux);
    void copiaVetor(Item ** copia);
    void menu();
};

#endif // TESTAORDENA_H

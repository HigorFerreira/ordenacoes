#include "TestaOrdena.h"
#include "time.h"
#include "Ordena.h"

TestaOrdena::TestaOrdena()
{

}

bool TestaOrdena::setTam(int tam){
    if(tam >= 100 && tam <= 100000){
        this->tam = tam;
        this->vetor = new Item *[tam];
        for(int i = 0; i < tam; i++)
            this->vetor[i] = 0;
        return true;
    }
    return false;
}

int TestaOrdena::getTam() const{
    return this->tam;
}

void TestaOrdena::preencheVetor(){
    int aux = 0;
    srand(17);

    for(int i = 0; i < this->tam; i++){
        aux = rand();
        aux = (aux+131)%this->tam+1;
        this->vetor[i] = new Item;
        this->vetor[i]->setChave(aux);
    }
}

void TestaOrdena::mostraVetor(Item **aux){
    for(int i = 0; i < this->tam; i++){
        cout<<aux[i]->getItem()<<endl;
    }
}

void TestaOrdena::copiaVetor(Item ** copia){
    copia = new Item *[this->tam];
    for(int i = 0; i < this->tam; i++){
        copia[i] = this->vetor[i];
    }
}

void TestaOrdena::menu(){
}

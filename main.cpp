#include <iostream>
#include "TestaOrdena.h"
#include "Ordena.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    TestaOrdena *obj = new TestaOrdena;
    obj->setTam(100);
    obj->preencheVetor();
    obj->mostraVetor(obj->getVetor());
    cout<<"Ordenando o vetor\n\n";
    Ordena::bubbleSort(obj->getVetor(), obj->getTam());
    obj->mostraVetor(obj->getVetor());
}

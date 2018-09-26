#include <iostream>
#include "TestaOrdena.h"
#include "Ordena.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    TestaOrdena *obj = new TestaOrdena;
    obj->setTam(100);
    obj->preencheVetor();
    obj->mostraVetor(obj->getVetor());
    cout<<"Ordenando o vetor\n\n";
    Ordena::shellSort(obj->getVetor(), obj->getTam());
    obj->mostraVetor(obj->getVetor());
}

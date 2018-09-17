#include "ordena.h"

Ordena::Ordena()
{

}

bool Ordena::insertionSort(Item **V, int n){
    long int i, j;
    Item *T = 0, *left = 0;
    if(V != 0){
        for(j = 1; j < n; j++){
            T = V[j];
            i = j-1;
            left = V[i];
            while(i >= 0 && left->getChave() > T->getChave()){
                (V[i+1]) = (V[i]);
                i--;
                left = V[i];
            }
            V[i+1] = T;
        }
        return true;
    }
    return false;
}

bool Ordena::selectionSort(Item **V, int n){
    long int i, j, imin;
    Item *T = 0, *left = 0, *right = 0;
    if(V != 0){
        for(i = 0; i < n - 1; i++){
            imin = i;
            for(j = i+1; j < n; j++){
                left = V[j];
                right = V[imin];
                if(left->getChave() < right->getChave()){
                    imin = j;
                }
            }
            if(i != imin){
                T = V[i];
                V[i] = V[imin];
                V[imin] = T;
                T = 0;
            }
        }
    }
    return false;
}

bool Ordena::mergeSort(Item ** V, int n){
	
}


bool Ordena::bubbleSort(Item **V, int n){
    long int Lsup, Bolha, j;
    Item * T;

    Lsup = n;
    do{
        T = 0;
        for(j = 0; j < Lsup - 1; ){
            if(V[j]->getChave() > V[j+1]->getChave()){
                T = V[j];
                V[j] = V[j+1];
                V[j+1] = T;
                Bolha = j;
            }
        }
        Lsup = Bolha;
    }while(Lsup <= 0);

    return true;
}

/*
void Ordena::heapSort(Item **V, int n){
}
*/

/*
*/

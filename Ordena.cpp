#include "Ordena.h"

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

void Ordena::mergeSort(Item **V, int n){
    if(V){
        Item **B = new Item*[n];
        int ini = 0;
        int fim = n-1;
        mergeSort(V, B, ini, fim);
        delete[] B;
    }
}

void Ordena::mergeSort(Item **A, Item **B, int ini, int fim){
    if(fim == ini){
        return;
    }
    else{
        int meio = (ini+fim)/2;
        mergeSort(A, B, ini, meio);
        mergeSort(A, B, meio+1, fim);
        intercala(A, B, ini, meio, fim);
        return;
    }
}

void Ordena::intercala(Item **A, Item **B, int ini, int meio, int fim){
    int i = ini, j = meio+1, k = ini;
    while(i<meio+1 && j<fim+1){
        if(A[i]->getChave() < A[j]->getChave()){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i<meio+1) {
       B[k] = A[i];
       k++;
       i++;
    }
    while (j<fim+1) {
       B[k] = A[j];
       k++;
       j++;
    }
    for(int k = ini; k<fim+1; k++){
        A[k] = B[k];
    }
}


bool Ordena::bubbleSort(Item **V, int n){
    long int Lsup, Bolha, j;
    Item * T;

    Lsup = n - 1;
    while(Lsup > 0)
    {
        T = 0;
        Bolha = 0;
        for(j = 0; j < Lsup; j++){
            if(V[j]->getChave() > V[j+1]->getChave()){
                T = V[j];
                V[j] = V[j+1];
                V[j+1] = T;
                Bolha = j;
            }
        }
        Lsup = Bolha;
    }

    return true;
}

bool Ordena::shellSort(Item **V, int n){
    int h = 1;

    while(h < n){
        h = h*3+1;
    }

    h = h/3;
    int c, j;

    while(h > 0){
        for(int i = h; i<n; i++){
            c = V[i]->getChave();
            j = i;
            while(j >= h && V[j - h]->getChave() > c){
                V[j] = V[j - h];
                j =  j - h;
            }
            Item *aux = new Item;
            aux->setChave(j);
            V[j] = aux;
        }
        h = h/2;
    }
}

void Ordena::quickSort(Item **V, int n){
	quickSort(V, 0, n-1);
}

void Ordena::quickSort(Item **V, int ini, int fim){
	int i, j;
	Item *pivo = new Item, *aux = new Item;
	
	i = ini;
	j = fim;
	pivo = V[(int)(ini + fim)/2];
	while(i <= j){
		while(V[i]->getChave() < pivo->getChave()){
			i += 1;
		}
		while(V[j]->getChave() > pivo->getChave()){
			j -= 1;
		}
		if(i <= j){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			i += 1;
			j -= 1;
		}
	}
	if(ini < j){
		quickSort(V, ini, j);
	}
	if(i < fim){
		quickSort(V, i, fim);
	}
}


void Ordena::criarHeap(Item ** vetor, int i, int f){
    Item *pai = vetor[i];
    int j=2*i+1;
    while(j<=f){
        if(j+1 <= f && vetor[j]->getChave()<vetor[j+1]->getChave())
        {
            j++;
        }
        if(pai->getChave()<vetor[j]->getChave()){
            vetor[i]=vetor[j];
            i=j;
            j=2*i+1;
        }
        else{
            j=f+1;
        }
        vetor[i]=pai;
    }
}

void Ordena::heapSort(Item **vetor, int tam){
    for (int i = (tam-1)/2; i>=0;i--){
        criarHeap(vetor,i,tam-1);
    }
    for(int i = tam-1; i>=1;i--){
        Item *aux;
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criarHeap(vetor,0,i-1);
    }
}

#ifndef ORDENA_H
#define ORDENA_H

#include "Item.h"

class Ordena
{
public:
    Ordena();
    static bool insertionSort(Item ** V, int n);
    static bool selectionSort(Item ** V, int n);

    static void intercala(Item **A, Item **B, int ini, int meio, int fim);
    static void mergeSort(Item ** V, int n);
    static void mergeSort(Item **A, Item **B, int ini, int fim);

    static bool shellSort(Item ** V, int n);
    static bool bubbleSort(Item ** V, int n);
    static void heapSort(Item ** V, int n);
    static void quickSort(Item **V, int n);
    static void quickSort(Item ** V, int ini, int fim);
};

#endif // ORDENA_H

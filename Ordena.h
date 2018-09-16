#ifndef ORDENA_H
#define ORDENA_H

#include "item.h"

class Ordena
{
public:
    Ordena();
    static void insertionSort(Item ** V, int n);
    static bool selectionSort(Item ** V, int n);
    static void heapSort(Item ** V, int n);
};

#endif // ORDENA_H

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
    /*this->tam = 100;
    preencheVetor();*/
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

Item ** TestaOrdena::copiaVetor(){
    Item **copia = new Item *[this->tam];
    for(int i = 0; i < this->tam; i++){
        copia[i] = this->vetor[i];
    }
    return copia;
}

void TestaOrdena::menu(){
	//Menu será feito aqui
    short option;
    cout<<"===========================================\n";
    cout<<"-------- TESTES DE ALGORITMOS -------------\n";
    cout<<"Selecione o numero de elementos para testar\nos algoritmos de ordenacao\n\n";
    cout<<"1 - 100\n";
    cout<<"2 - 1000\n";
    cout<<"3 - 10000\n";
    cout<<"4 - 100000\n";
    cout<<"5 - Testar todos os casos\n";
    cout<<"------------------->";
    cin>>option;

    int elementos;

    //========== Vetor com o nome dos algoritmos de ordenação
    char **algNames = new char*[7];

    algNames[0] = new char[9];
    algNames[0] = "Insertion";
    algNames[1] = new char[9];
    algNames[1] = "Selection";
    algNames[2] = new char[5];
    algNames[2] = "Merge";
    algNames[3] = new char[5];
    algNames[3] = "Shell";
    algNames[4] = new char[6];
    algNames[4] = "Bubble";
    algNames[5] = new char[5];
    algNames[5] = "Quick";
    algNames[6] = new char[4];
    algNames[6] = "Heap";

    switch(option){
        case 1:
            elementos = 100;
            break;
        case 2:
            elementos = 1000;
            break;
        case 3:
            elementos = 10000;
            break;
        case 4:
            elementos = 100000;
            break;
        case 5:
            elementos = -1;
            break;
        default:
            elementos = -500;
            break;
    }

    if(elementos > 0){

    }
    else if(elementos == -1){

    }
    else{

    }
}

void TestaOrdena::print(int i, int n, char **algNames){
    cout<<"===========================================\n";
    cout<<"      Testando "<<algNames[i]<<" Sort\n";
    cout<<"-------------------------------------------\n";
    cout<<"Copiando o vetor...\n";
    Item **vect = copiaVetor();
    cout<<"Vetor copiado\n";
    time_t startTime = time(0);
    cout<<"Ordenando o vetor...\n";
    switch (i) {
    case 0:
        Ordena::insertionSort(vect, n);
        break;
    case 1:
        Ordena::selectionSort(vect, n);
        break;
    case 2:
        Ordena::mergeSort(vect, n);
        break;
    case 3:
        Ordena::shellSort(vect, n);
        break;
    case 4:
        Ordena::bubbleSort(vect, n);
        break;
    case 5:
        Ordena::quickSort(vect, n);
        break;
    case 6:
        Ordena::heapSort(vect, n);
        break;
    default:
        cout<<"Erro de chamada de metodo\n";
        break;
    }
    cout<<"Vetor ordenado...\n";
    cout<<"Tempo de ordenacao: "<<difftime(time(0), startTime)<<endl;
}

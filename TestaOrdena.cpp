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
	//Menu ser� feito aqui
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

    //========== Vetor com o nome dos algoritmos de ordena��o
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
    algNames[5] = new char[4];
    algNames[5] = "Heap";
    algNames[6] = new char[5];
    algNames[6] = "Quick";

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
            elementos = -2;
            break;
        default:
            elementos = -1;
            break;
    }
}

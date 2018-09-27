#include "TestaOrdena.h"
#include "time.h"
#include "Ordena.h"

TestaOrdena::TestaOrdena()
{

}

Item ** TestaOrdena::getVector(){
    return this->vetor;
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

void TestaOrdena::copiaVetor(Item ** copia){
    copia = new Item *[this->tam];
    for(int i = 0; i < this->tam; i++){
        copia[i] = this->vetor[i];
    }
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
    cout<<"------------------->";
    cin>>option;

    int elementos;
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
        default:
            tratarEntrada();
            break;
    }

    /* Chamada dos métodos de ordenação */
    insertion(elementos);
    /*
    selection(elementos);
    merge(elementos);
    shell(elementos);
    bubble(elementos);
    quick(elementos);
    //heap(elementos);
    */

    cout<<endl<<endl;
    menu();
}

void TestaOrdena::tratarEntrada(){

}

void TestaOrdena::insertion(int n){
    cout<<"===========================================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::insertionSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

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
	//Menu ser� feito aqui
    short option;
    cout<<"===========================================\n";
    cout<<"-------- TESTES DE ALGORITMOS -------------\n";
    cout<<"Selecione o numero de elementos para testar\nos algoritmos de ordenacao\n\n";
    cout<<"1 - 100\n";
    cout<<"2 - 1000\n";
    cout<<"3 - 10000\n";
    cout<<"4 - 100000\n";
    cout<<"5 - Testar todos\n";
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
        case 5:
			elementos = -1;
			break;    	
        default:
            elementos = -1000;
            break;
    }

    /* Chamada dos m�todos de ordena��o */
    if(elementos > 0)
    	callAll(elementos);
    else if(elementos == -1){
    	elementos = 100;
    	int i = 1;
    	while(elementos <= 100000){
    		cout<<"\n================================================================ TESTE-"<<i<<": "<<elementos<<" elementos.\n";
    		callAll(elementos);
    		cout<<"\n================================================================ FIM TESTE-"<<i<<"\n";
    		elementos *= 10;
    		i++;
		}
	}
	else{
		cout<<"\nESCOLHA UMA OPCAO VALIDA\n";
	}

    cout<<endl<<endl;
    menu();
}

void TestaOrdena::callAll(int elementos){
	insertion(elementos);
    selection(elementos);
    merge(elementos);
    shell(elementos);
    //bubble(elementos);
    quick(elementos);
    //heap(elementos);
}

void TestaOrdena::insertion(int n){
    cout<<"===========================================\n";
    cout<<"==============INSERTION SORT===============\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::insertionSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::selection(int n){
    cout<<"===========================================\n";
    cout<<"==============SELECTION SORT===============\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::selectionSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::merge(int n){
    cout<<"===========================================\n";
    cout<<"==============MERGE SORT===================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::mergeSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::shell(int n){
    cout<<"===========================================\n";
    cout<<"==============SHELL SORT===================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::shellSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::bubble(int n){
    cout<<"===========================================\n";
    cout<<"==============BUBBLE SORT==================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::bubbleSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::quick(int n){
    cout<<"===========================================\n";
    cout<<"==============QUICK SORT===================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::quickSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

void TestaOrdena::heap(int n){
    cout<<"===========================================\n";
    cout<<"==============HEAP SORT====================\n";
    cout<<"Populando vetor com "<<n<<" elementos.\n";
    TestaOrdena *o = new TestaOrdena;
    o->setTam(n);
    o->preencheVetor();
    cout<<"Ordenando vetor...\n";
    time_t start = time(0);
    Ordena::heapSort(o->getVector(), o->getTam());
    cout<<"Tempo de ordenacao: "<<difftime(time(0), start)<<" segundos"<<endl;
}

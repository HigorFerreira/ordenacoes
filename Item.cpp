#include "item.h"

Item::Item()
{

}

void Item::setChave(int chave){
    this->chave = chave;
}

int Item::getChave() const{
    return this->chave;
}

void Item::setStr(string str){
    this->str = str;
}

string Item::getStr() const{
    return this->str;
}

string Item::getItem(){
    string aux = "";
    aux += to_string(this->chave);
    aux += " ";
    aux += this->str;
    aux += "\n";
    return aux;
}

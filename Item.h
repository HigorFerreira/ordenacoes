#ifndef ITEM_H
#define ITEM_H

#include<string>

using namespace std;

class Item
{
    int chave;
    string str;
public:
    Item();
    void setChave(int);
    void setStr(string);
    int getChave() const;
    string getStr() const;
    string getItem();
};

#endif // ITEM_H

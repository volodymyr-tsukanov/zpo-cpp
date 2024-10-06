#include "Map.h"


Map::Map()
{
    //ctor
}
Map::~Map()
{
    tab.clear();
    cTab.clear();
}


void Map::add(string elem)
{
    int i = 0;
    while(i++ < tab.size())
        if(tab[i] == elem){
            cTab[i] = cTab[i]+1;
            i = tab.size()+2;
        }
    }

    if(i != tab.size()+2){
        tab.push_back(elem);
        cTab.push_back(1);
    }
}

void Map::rmv(string elem)
{

}

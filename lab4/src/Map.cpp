#include "Map.h"


int Map::getSize()
{
    return tab.size();
}


void Map::add(string elem, bool force_push){
    Entry e;
    e.key = elem;
    e.value = 1;
    tab.push_back(e);
    cout << "add "<<elem << endl;
}
void Map::add(string elem)
{
    if(tab.empty()){
        add(elem, true);
    } else{
        bool nFound = true;
        list<Entry>::iterator it = tab.begin();
        while(it++ != tab.end()){
            if((*it).key == elem){
                (*it).value++;
                cout << "found "<<elem << endl;
                nFound = false;
                break;
            }
        }
        if(nFound){
            add(elem, true);
        }
    }
}

void Map::rmv(string elem)
{
    if(tab.size() > 0){
        list<Entry>::iterator it = tab.begin();
        while(it++ != tab.end()){
            if((*it).key == elem){
                tab.erase(it);
                break;
            }
        }
    }
}


void Map::print()
{
    auto it = tab.begin();
    while(it != tab.end()){
        cout <<(*it).key<<" = "<<(*it).value << endl;
        it++;
    }
}

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <list>

using namespace std;


class Map
{
private:
    list<int> cTab;
    list<string> tab;

public:
    Map();
    ~Map();

    void add(string elem);
    void rmv(string elem);
};

#endif // MAP_H

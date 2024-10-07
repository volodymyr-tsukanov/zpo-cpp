#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Map
{
protected:
    struct Entry{
        string key;
        int value;
    };

private:
    list<Entry> tab;

    void add(string elem, bool force_push);

public:
    int getSize();

    void add(string elem);
    void rmv(string elem);

    void print();
};

#endif // MAP_H

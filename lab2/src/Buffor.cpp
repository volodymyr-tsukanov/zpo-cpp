#include "Buffor.h"


Buffor::Buffor(int _size)
{
    tab = (int*) malloc(_size * sizeof(int));
    n = _size;
    freeIndex = 0;
    allocStep = 5;
}
Buffor::~Buffor()
{
    free(tab);
    cout << "freed allocated space" << endl;
}


int Buffor::getIndex()
{
    return freeIndex;
}
int Buffor::getSize()
{
    return n;
}
int Buffor::getTab(int i)
{
    if(i == 0) return getFirst();
    else if(i > 0 && i < n) return tab[i];
    else return ERROR_VALUE;
}
int Buffor::getFirst()
{
    if(n > 0) return tab[0];
    else return ERROR_VALUE;
}

void Buffor::setAllocStep(int step){
    allocStep = step;
}
void Buffor::setTab(int pos, int value)
{
    if(pos == 0) setFirst(value);
    else if(pos > 0 && pos < n) tab[pos] = value;
}
void Buffor::setFirst(int value)
{
    if(n > 0) tab[0] = value;
}


void Buffor::add(int value)
{
    if(n == freeIndex){
        n += allocStep;
        tab = (int*) realloc(tab, n * sizeof(int));
    } else{
        tab[freeIndex++] = value;
    }
}


void Buffor::show()
{
    if(n == 0){
        cout << "buffor empty" << endl;
    } else {
        cout << "buffor:" << endl;
        for(int i = 0; i < n; i++){
            cout << "  "<<i<<") "<<tab[i] << endl;
        }
    }
}

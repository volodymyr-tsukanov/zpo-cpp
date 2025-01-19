#include "MaxBufor.h"


void MaxBufor::add(int value)
{
    if(getSize() == getIndex()){
        cout << "max buffor run out of space" << endl;
    } else{
        Buffor::add(value);
    }
}

double MaxBufor::calculate()
{
    double m = getFirst();
    for(int i = 1; i < getSize(); i++){
        int value = getTab(i);
        if(value > m) m = value;
    }
    return m;
}

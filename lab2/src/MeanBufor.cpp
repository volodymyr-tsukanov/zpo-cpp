#include "MeanBufor.h"


double MeanBufor::calculate()
{
    double m = 0.0;
    for(int i = 0; i < getSize(); i++){
        m += getTab(i);
    }
    m /= getSize();
    return m;
}

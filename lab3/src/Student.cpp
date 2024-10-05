#include "Student.h"

template<>
void Student<int>::showMark()
{
    cout <<"Twoja ocena to: "<<mark<<endl;
}

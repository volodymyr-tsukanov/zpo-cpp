#include "Array.h"


template <>
bool Array<string>::isGreater(string a, string b){
    return a.length() > b.length();
}

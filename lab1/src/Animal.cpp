#include "Animal.h"

Animal::Animal()
{
    //ctor
}

Animal::Animal(bool _protectedAnimal, int _limbNr, string _name){
    protectedAnimal = _protectedAnimal;
    limbNr = _limbNr;
    name = _name;
}


string Animal::getName(){
    return name;
}
int Animal::getLimbNr(){
    return limbNr;
}
bool Animal::getProtectedAnimal(){
    return protectedAnimal;
}

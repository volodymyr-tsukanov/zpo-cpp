#include "City.h"


City::~City()
{
    citizens.clear();
}


string City::getCityName(){
    return city_name;
}


int City::city_citizens()
{
    return citizens.size();
}

int City::women()
{
    return count_if(citizens.begin(), citizens.end(), [](Citizen& c){
                    return c.getSex() == 'w';
                    });
}

int City::adults()
{
    return count_if(citizens.begin(), citizens.end(), [](Citizen& c){
                    return c.getAge() >= 18;
                    });
}

int City::postalCodesCount()
{
    return postalCodes.getSize();
}


void City::addCitizen(Citizen citizen)
{
    citizens.push_back(citizen);
    postalCodes.add(citizen.getPostalCode());
}

bool City::deleteCitizen(string surname, int age)
{
    vector<Citizen>::iterator citizen = find_if(citizens.begin(), citizens.end(), [surname, age](Citizen& c){
              return  c.getSurname() == surname && c.getAge() == age;
              });

    if(citizen == citizens.end()) return false;
    else{
        postalCodes.rmv((*citizen).getPostalCode());
        citizens.erase(citizen);
        return true;
    }
}


void City::show_city()
{
    cout << "Welcome to the city of "<<city_name << endl;
}

void City::show_citizens()
{
    cout << "Citizens:-{" << endl;
    for_each(citizens.begin(), citizens.end(), [](Citizen& c){
             cout << "  * ";
             c.show();
             });
    cout << "}\n\n" << endl;
}

void City::postal_codes()
{
    cout << "Postal code stats:-{" << endl;
    postalCodes.print();
    cout << "}\n\n" << endl;
}


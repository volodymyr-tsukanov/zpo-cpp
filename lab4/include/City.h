#ifndef CITY_H
#define CITY_H
#include <vector>
#include <algorithm>
#include "Citizen.h"
#include "Map.h"

using namespace std;


class City
{
private:
    string city_name;
    vector<Citizen> citizens;
    Map postalCodes;

public:
    City(string _cityName) : city_name(_cityName){};
    ~City();

    string getCityName();

    int city_citizens();
    int women();
    int adults();
    int postalCodesCount();

    void addCitizen(Citizen citizen);
    bool deleteCitizen(string surname, int age);

    void show_city();
    void show_citizens();
    void postal_codes();
};

#endif // CITY_H

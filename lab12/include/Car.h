#include <iostream>
#include <algorithm>
#include <tuple>
#ifndef CAR_H
#define CAR_H


class Car {
private:
    std::tuple<std::string, int, double> carData;  // model, year, engine capacity

public:
    Car(std::string model, int year, double capacity) :
        carData(make_tuple(model, year, capacity)) {}

    // Getters using get<N> for tuple access
    std::string getModel() const { return std::get<0>(carData); }
    int getYear() const { return std::get<1>(carData); }
    double getEngineCapacity() const { return std::get<2>(carData); }

    // Setters using get<N> for tuple access
    void setModel(const std::string& m) { std::get<0>(carData) = m; }
    void setYear(int y) { std::get<1>(carData) = y; }
    void setEngineCapacity(double c) { std::get<2>(carData) = c; }

    // Display method with counter
    void display(int counter) const {
        std::cout << counter << ". Model: " << std::get<0>(carData)
             << ", Year: " << std::get<1>(carData)
             << ", Engine: " << std::get<2>(carData) << "L" << std::endl;
    }
};

#endif // CAR_H

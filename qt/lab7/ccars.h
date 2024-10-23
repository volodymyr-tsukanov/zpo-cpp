#ifndef CCARS_H
#define CCARS_H
#include <iostream>
#include <QVector>


class Car {
private:
    std::string make;       // Marka samochodu
    std::string model;      // Model samochodu
    int year;           // Rok produkcji
    std::string vin;        // Numer VIN

public:
    // Constructor
    Car(const std::string& make, const std::string& model, int year, const std::string& vin)
        : make(make), model(model), year(year), vin(vin) {}


    // Getters
    std::string getMake() const {
        return make;
    }
    std::string getModel() const {
        return model;
    }
    int getYear() const {
        return year;
    }
    std::string getVin() const {
        return vin;
    }

    // Setters
    void setMake(const std::string& make) {
        this->make = make;
    }
    void setModel(const std::string& model) {
        this->model = model;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setVin(const std::string& vin) {
        this->vin = vin;
    }
};



class CCars {
private:
    QVector<Car> cars; // Vector to hold the cars

public:
    // Add a new car to the catalog
    void addCar(const Car& car) {
        cars.append(car);
    }

    // Display cars in the catalog
    void displayCars() const {
        for (const auto& car : cars) {
            std::cout << "Make:" << car.getMake()
                     << ", Model:" << car.getModel()
                     << ", Year:" << car.getYear()
                     << ", VIN:" << car.getVin();
        }
    }

    // Count cars older than a given year
    int countOlderThan(int year) const {
        return std::count_if(cars.begin(), cars.end(), [year](const Car& car) {
            return car.getYear() < year;
        });
    }

    // Remove a car by VIN
    void removeCarByVin(const std::string& vin) {
        auto it = std::remove_if(cars.begin(), cars.end(), [&vin](const Car& car) {
            return car.getVin() == vin;
        });
        cars.erase(it, cars.end());
    }

    // Sort cars by year (descending)
    void sortCarsYear() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getYear() > b.getYear(); // Descending order by year
        });
    }
    // sort by make (ascending)
    void sortCarsMake() {
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.getMake() < b.getMake(); // Descending order by year
        });
    }
};


#endif // CCARS_H

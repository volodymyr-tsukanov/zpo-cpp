#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include "Car.h"

using namespace std;


void printVector(const vector<int>& vec) {
    for_each(vec.begin(), vec.end(),
        [](int x) { cout << x << "|"; });
    cout << endl;
}

double calculateMean(const vector<int>& vec) {
    if (vec.empty()) return 0.0;
    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}

int countEven(const vector<int>& vec) {
    return count_if(vec.begin(), vec.end(),
        [](int x) { return x % 2 == 0; });
}
void removeNegative(vector<int>& vec) {
    vec.erase(
        remove_if(vec.begin(), vec.end(),
            [](int x) { return x < 0; }),
        vec.end());
}
void sortEvenOdd(vector<int>& vec) {
    stable_sort(vec.begin(), vec.end(),
        [](int a, int b) {
            return (a % 2 == 0) > (b % 2 == 0);
        });
}
void makeOpposite(vector<int>& vec) {
    transform(vec.begin(), vec.end(), vec.begin(),
        [](int x) { return -x; });
}
int countLessThan(const vector<int>& vec, int value) {
    return count_if(vec.begin(), vec.end(),
        [value](int x) { return x < value; });
}

// Function returns tuple with: min length, average length, longest string
tuple<size_t, double, string> getStringStats(const vector<string>& strings) {
    // Handle empty container case
    if (strings.empty()) {
        return make_tuple(0, 0.0, "");
    }

    // Find shortest string length using min_element and lambda
    auto minLength = min_element(strings.begin(), strings.end(),
        [](const string& a, const string& b) {
            return a.length() < b.length();
        })->length();

    // Calculate average length using accumulate and lambda
    auto totalLength = accumulate(strings.begin(), strings.end(), 0LL,
        [](long long sum, const string& str) {
            return sum + str.length();
        });
    double averageLength = double(totalLength) / strings.size();

    // Find longest string using max_element and lambda
    auto longestString = *max_element(strings.begin(), strings.end(),
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });

    return make_tuple(minLength, averageLength, longestString);
}


int main()
{
    int zadN = 1;
    while(zadN != 0){
        printf("n?: ");
        cin >> zadN;

        switch(zadN){
        case 1:
        {
            vector<int> numbers = {1, -2, 3, -4, 5, 6, -7, 8, 9, 10};

            cout << "Original vector: ";
            printVector(numbers);

            cout << "Mean: " << fixed << setprecision(2)
                      << calculateMean(numbers) << endl;

            cout << "Number of even elements: "
                      << countEven(numbers) << endl;

            removeNegative(numbers);
            cout << "After removing negative numbers: ";
            printVector(numbers);

            sortEvenOdd(numbers);
            cout << "After sorting (even first): ";
            printVector(numbers);

            makeOpposite(numbers);
            cout << "After making opposite: ";
            printVector(numbers);

            int threshold = 5;
            cout << "Elements less than " << threshold << ": "
                      << countLessThan(numbers, threshold) << endl;
        }
        break;
        case 2:
        {
            // Create vector of cars
            vector<Car> cars = {
                Car("Toyota Corolla", 2020, 1.8),
                Car("Honda Civic", 2022, 1.5),
                Car("Ford Mustang", 2029, 5.0),
                Car("BMW M3", 2021, 3.0)
            };

            // Sort by year (ascending) using lambda
            cout << "Cars sorted by year (ascending):" << endl;
            sort(cars.begin(), cars.end(),
                [](const Car& a, const Car& b) {
                    return a.getYear() < b.getYear();
                });

            // Display sorted by year
            for(int i = 0; i < cars.size(); i++) {
                cars[i].display(i + 1);
            }

            cout << "\nCars sorted by engine capacity (descending):" << endl;
            // Sort by engine capacity (descending) using lambda
            sort(cars.begin(), cars.end(),
                [](const Car& a, const Car& b) {
                    return a.getEngineCapacity() > b.getEngineCapacity();
                });

            // Display sorted by engine capacity
            for(int i = 0; i < cars.size(); i++) {
                cars[i].display(i + 1);
            }
        }
        break;
        case 3:
        {
            // Test vector of strings
            vector<string> texts = {
                "Hello",
                "C++ Programming",
                "Test",
                "Algorithm and Data Structures"
            };

            // Get statistics
            auto [min_len, avg_len, longest] = getStringStats(texts);

            // Display results
            cout << "Shortest string length: " << min_len << endl;
            cout << "Average string length: " << avg_len << endl;
            cout << "Longest string: " << longest << endl;
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }

    return 0;
}

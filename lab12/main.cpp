#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

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
        }
        break;
        case 3:
        {
        }
        break;
        case 4:
        {
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }

    return 0;
}

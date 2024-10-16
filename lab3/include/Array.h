#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <typeinfo>

using namespace std;


template <typename T>
class Array
{
private:
    int n, freeIndex, maxIndex;
    T* tab;

protected:
    bool isGreater(T a, T b);

public:
    Array(int _size);
    Array() : Array(10){};
    Array(initializer_list<T> il);
    ~Array();

    T getByIndex(int index);
    T getMax();
    void add(T value);

    void sortAsc();
    void show();
};


template <typename T>
Array<T>::Array(int _size)
{
    tab = new T[_size];
    n = _size;
}
template <typename T>
Array<T>::Array(initializer_list<T> il)
{
    tab = new T[il.size()];
    n = il.size();

    for(auto it = il.begin(); it != il.end(); ++it) add(*it);
}
template <typename T>
Array<T>::~Array()
{
    delete[] tab;
}

template <typename T>
T Array<T>::getByIndex(int index)
{
    return tab[index];
}
template <typename T>
T Array<T>::getMax()
{
    return tab[maxIndex];
}

template <typename T>
void Array<T>::add(T value)
{
    if (freeIndex == 0){
        tab[0] = value;
        maxIndex = freeIndex++;
    } else if(freeIndex < n){
        tab[freeIndex] = value;
        if(isGreater(value, tab[maxIndex])) maxIndex = freeIndex;
        freeIndex++;
    }
}


template <typename T>
bool Array<T>::isGreater(T a, T b){
    return a > b;
}
template <>
bool Array<string>::isGreater(string a, string b) {
    return a.length() > b.length();
}


template <typename T>
void Array<T>::sortAsc()
{
    swap(tab[maxIndex], tab[n-1]);  //max is known => less work to do
    for(int i = 0; i < n-2; i++){
        int minIndex = i;
        for(int j = i+1; j < n-1; j++){
            if(isGreater(tab[minIndex], tab[j])) minIndex = j;
        }
        swap(tab[minIndex], tab[i]);
    }
}

template <typename T>
void Array<T>::show()
{
    cout << "array "<<typeid(T).name()<<": " << endl;
    for(int i = 0; i < n; i++){
        cout << i<<") "<<tab[i] << endl;
    }
}



#endif // ARRAY_H

/*Dokonaj specjalizacji klasy Array dla typu string, w taki sposób aby:
• metoda sortująca sortowała słowa pod względem ich długości;
• metoda zwracająca element maksymalny zwracała najdłuższy napis znajdujący się
w tablicy.*/

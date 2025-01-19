#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

using namespace std;


class Buffer
{
public:
    Buffer() {
        cout << "Konstruktor Buffer" << endl;
    }
    
    virtual ~Buffer() {
        cout << "Destruktor Buffer" << endl;
    }

    virtual void add(int a) = 0;
    virtual void write() = 0;
};


class BufferArr : public Buffer {
private:
    unique_ptr<int[]> arr;
    int _size;
    int _count;

public:
    BufferArr(int size) : _size(size), _count(0) {
        arr = make_unique<int[]>(size);
        cout << "Konstruktor klasy BufferArr" << endl;
    }

    ~BufferArr() override {
        arr.reset();
        cout << "Destruktor klasy BufferArr" << endl;
    }

    void add(int a) override {
        if (_count < _size) {
            arr[_count++] = a;
        } else {
            cout << "Tablica jest pełna, nie można dodać elementu: " << a << endl;
        }
    }

    void write() override {
        for (int i = 0; i < _count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class BufferFile : public Buffer {
private:
    string filePath;

public:
    BufferFile(const string& path) : filePath(path) {
        cout << "Konstruktor klasy BufferFile" << endl;
    }

    ~BufferFile() override {
        cout << "Destruktor klasy BufferFile" << endl;
    }

    void add(int a) override {
        ofstream file(filePath);
        if (file.is_open()) {
            file << a << endl;
            file.close();
        } else {
            cerr << "Nie można otworzyć pliku do zapisu: " << filePath << endl;
        }
    }

    void write() override {
        ifstream file(filePath);
        if (file.is_open()) {
            int number;
            while (file >> number) {
                cout << number << " ";
            }
            file.close();
            cout << endl;
        } else {
            cerr << "Nie można otworzyć pliku do odczytu: " << filePath << endl;
        }
    }
};

#endif // BUFFER_H

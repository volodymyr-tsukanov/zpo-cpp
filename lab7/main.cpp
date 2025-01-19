#include <boost/bind.hpp>
#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QSet>
#include <QtAlgorithms>
#include <QDebug>
#include <QString>
#include "ccars.h"

using namespace std;


class Compare {
public:
    bool operator()(int s1, int s2) {
        if (s1 % 2 > s2 % 2)
            return true;
        else
            return false;
    }
};



template<typename T>
void show(QVector<T> vec) {
    cout << "Zawartosc vec: :";
    typename QVector<T>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p) {
        cout << *p << " ";
    }
    cout << endl;
}

bool isPangram(const QString& text) {
    // Tworzymy zbiór, który będzie przechowywał unikalne litery alfabetu
    QSet<QChar> letters;

    // Przechodzimy przez każdy znak w napisie
    for (QChar c : text) {
        // Ignorujemy znaki, które nie są literami alfabetu
        if (c.isLetter()) {
            // Dodajemy literę do zbioru, konwertując na małą literę
            letters.insert(c.toLower());
        }
    }

    // Sprawdzamy, czy w zbiorze znajdują się wszystkie litery alfabetu
    return letters.size() == 26;
}


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    /*listing */
            QVector<int> vec(6);

            vec[0] = 1;
            vec[1] = 2;
            vec.append(2);
            vec.push_back(4);
            vec << 5 << 6;

            cout << "Zawartosc vec: :";
            for (int i = 0; i < vec.count(); ++i) {
                cout << vec[i] << " ";
            }
            cout << endl << "Zawartosc vec: :";
            for (int i = 0; i < vec.size(); ++i) {
                cout << vec.at(i) << " ";
            }
            cout << endl << "Zawartosc vec: :";

            QVectorIterator<int> i(vec);
            while (i.hasNext()) {
                cout << i.next() << " ";
            }
            cout << endl;

            show(vec);
            cout << "Zawartosc vec: :";

            QVector<int>::iterator p;
            for (p = vec.begin(); p != vec.end(); ++p) {
                *p += 2;
                cout << *p << " ";
            }
            cout << endl;

            vec.insert(1, 666);
            vec.insert(vec.begin(), 777);
            show(vec);

            cout << "Ostatni indeks gdzie 2: " << vec.lastIndexOf(2) << endl;
            vec.move(1, vec.length() - 1);
            vec.remove(3);
            show(vec);

            //
            QMap<int, QString> shops;
            shops[111] = "CCC";
            shops[222] = "Decathlon";
            shops.insert(333, "Reserved");

            QMapIterator<int, QString> j(shops);
            while (j.hasNext()) {
                j.next();
                cout << "Id: " << j.key() << " sklep: " << j.value().toStdString() << endl;
            }

            QList<int> keys = shops.keys();
            QList<QString> values = shops.values();

            cout << "Klucze: " << endl;
            for (int i = 0; i < keys.size(); i++) {
                cout << keys[i] << " ";
            }
            cout << endl;

            QPair<QMap<int, QString>::iterator, QMap<int, QString>::iterator> range = shops.equal_range(111);
            cout << "Wartosc, dla klucza 111: " << range.first->toStdString() << endl;

            //
            cout << endl << "Zawartosc vec: ";
            QVectorIterator<int> it(vec);
            while (it.hasNext()) {
                cout << it.next() << " ";
            }
            cout << endl;

            QMutableVectorIterator<int> itM(vec);
            while (itM.hasNext()) {
                itM.next();
                itM.setValue(-1);
            }

            itM.toFront();
            cout << endl << "Zawartosc vec: ";
            while (itM.hasNext()) {
                cout << itM.next() << " ";
            }

            //
            /*show(vec);
            int howMany = 0;
            qCount(vec.begin(), vec.end(), 2, howMany);
            cout << "Liczba wystapien 2: " << howMany << endl;

            QVector<int>::iterator it2 = qt::qFind(vec.begin(), vec.end(), -2);
            if (it2 == vec.end()) {
                cout << "Element nie zostal znaleziony" << endl;
            }

            qSort(vec.begin(), vec.end(), qGreater<int>());
            show(vec);

            qSort(vec.begin(), vec.end(), Compare());
            show(vec);*/

    cout << "\n\n";

    /*zad7.1 ccars.h*/
        CCars cars;
        cars.addCar(Car("Volvo", "V8", 2003, "ER341289"));
        cars.addCar(Car("Toyota", "V6", 2010, "TY984567"));
        cars.addCar(Car("Honda", "I4", 2015, "HN123456"));
        cars.addCar(Car("Ford", "V6", 2018, "FD567890"));
        cars.addCar(Car("Chevrolet", "V8", 2020, "CH345678"));
        cars.addCar(Car("BMW", "I6", 2012, "BM234567"));
        cars.addCar(Car("Audi", "I4", 2016, "AU456789"));
        cars.addCar(Car("Mercedes-Benz", "V8", 2019, "MB987654"));
        cars.addCar(Car("Nissan", "V6", 2008, "NS123890"));
        cars.addCar(Car("Hyundai", "I4", 2021, "HY765432"));
        cars.displayCars();
        qDebug() << "\nSorted by y";
        cars.sortCarsYear(); cars.displayCars();
        cars.removeCarByVin("NS123890");
        qDebug() << "\nSorted by m";
        cars.sortCarsMake(); cars.displayCars();

    qDebug() << "\n\n\n";

    /*zad7.2 Panagram*/
        QString test1 = "The quick brown fox jumps over the lazy dog";
        QString test2 = "Hello World";
        qDebug() << "Test 1: " << (isPangram(test1) ? "Pangram" : "Nie pangram");
        qDebug() << "Test 2: " << (isPangram(test2) ? "Pangram" : "Nie pangram");

    return a.exec();
}


/*
Zadanie 7.1. Katalog samochodów
Napisz aplikację okienkową, która będzie obsługiwała katalog samochodów i umożliwi:
• przechowywanie informacji o samochodzie:
o marka i model samochodu,
o rok produkcji,
o numer VIN.
• dodanie nowego samochodu do katalogu;
• wyświetlenie samochodów z katalogu;
• policzenie samochodów starszych niż podany rok produkcji;
• usunięcie samochodu o podanym numerze VIN;
• wyświetlenie samochodów z katalogu w następującym porządku:
o malejąco względem roku produkcji
o alfabetycznym od a do z względem marki samochodu
Do przechowywania samochodów należy wykorzystać kontener z biblioteki Qt.

Zadanie 7.2. Pangram
Napisz funkcję, która jako argument dostaje napis. Zadaniem funkcji jest sprawdzenie czy
napis jest pangramem. Pangram to napis, w którym występują wszystkie litery alfabetu
(wielkość liter nie ma znaczenia). W zadaniu bierzemy pod uwagę tylko alfabet łaciński.
Przykład pangramu to: The quick brown fox jumps over the lazy dog. W zadaniu należy
wykorzystać kontener QSet. W funkcji main należy przetestować stworzoną funkcję.

Zadanie 7.3. Kraje
Napisz aplikację okienkową, która będzie obsługiwała informację o kraju oraz liczbie
ludności. Aplikacja ma umożliwiać:
• dodanie nowego kraju wraz z liczbą ludności;
• wyświetlenie krajów wraz z liczbą ludności;
• wyświetlenie samych krajów;
• wyświetlenie krajów z podanego zakresu;
• usunięcie kraju o podanej nazwie;
• wyświetlenie krajów wraz z liczbą mieszkańców rosnąco lub malejąco względem liczby
mieszkańców.
Podpowiedź: Do sortowania można użyć QVector, którego element będzie miał typ
QPair.
Do przechowywania informacji o kraju należy wykorzystać QMap lub QHash.*/


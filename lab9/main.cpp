#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>
#include <algorithm>
#include "Error.h"
#include "Student.h"

using namespace std;


void clearCin(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void saveToCSV(vector<Student>& students, string filename, char g='-') {
    ofstream file(filename);
    if (!file.is_open())
        throw FileError("Nie można otworzyć pliku: " + filename);

    file << "Imię;Nazwisko;Płeć;Ocena;Email\n";
    for (const auto& student : students) {
        if(g == '-' || g == student.gender){
            file << student.firstName << ";"
                << student.lastName << ";"
                << student.gender << ";"
                << student.grade << ";"
                << student.email << "\n";
        }
    }

    file.close();
}

void loadStudents(string filename, vector<Student>& students) {
    ifstream file(filename);
    if (!file.is_open())
        throw FileError("Nie można otworzyć pliku: " + filename);

    file.ignore(numeric_limits<streamsize>::max(), '\n'); //skip header
    string line;
    while (getline(file, line)) {
        students.emplace_back(line);
    }
    file.close();
}


int main()
{
    int zadN = 1;
    while(zadN != 0){
        printf("n?: ");
        cin >> zadN;

        switch(zadN){
        case -1:
        {
            int a = 223;
            float b=21.365;
            cout << "dec: "<< dec << a <<endl;
            cout << "hex bez showbase: "<< hex <<a <<endl;
            cout << "hex z showbase: " <<showbase<< a<<endl;
            cout << "oct z showbase: "<< oct << a<< endl;
            cout << "oct bez showbase: "<<noshowbase<< a << endl;
            cout << "dec z showpos: "<<dec<<showpos<< a << endl;
            cout<<"scientific: "<<scientific<<b<<endl;
            cout<<"setw z right: "<<setw(20)<<a<<endl;
            cout<<"setw z left i setfill: "<<setw(20)<<left<<setfill('*')<<a<<endl;
            cout<<"setprecision 3: "<<resetiosflags(ios::scientific)<<setprecision(3)<<b<<endl;


            string l1, l2, l3 = "Ala Nowak";
            int num;

            cout << "Konwersja: " << endl;
            istringstream isstream("123");
            isstream >> num;
            cout << num << endl;

            ostringstream osstream;
            osstream << 123;
            l1 = osstream.str();
            cout << l1 << endl;

            ostringstream osstream1;
            osstream1 << "Laboratorium " << 9 << ", zostalo jeszcze " << 6 << endl;
            cout << "Formatowanie: " << osstream1.str();

            string stringEx;
            int numberIntEx;
            float numberFloatEx;

            istringstream isstream1("Ala 10 3.45");
            isstream1 >> stringEx >> numberIntEx >> numberFloatEx;

            if (isstream1.fail()) {
                cout << "Parsowanie nie udalo sie" << endl;
            } else {
                cout << "Parsowanie udalo sie:" << endl;
                cout << "Napis: " << stringEx << endl;
                cout << "Liczba int: " << numberIntEx << endl;
                cout << "Liczba float: " << numberFloatEx << endl;
            }

            istringstream ss(l3);
            getline(ss, l1, ' ');
            getline(ss, l2, ' ');

            cout << l1 << " " << l2 << endl;


            ofstream fileOf;
            fileOf.open("plik.txt");
            if (fileOf.is_open()) {
                cout << "Plik otworzyl sie poprawnie" << endl;

                fileOf << "8 Ala ma kota" << endl;
                fileOf << "a kot ma Ale" << endl;
                fileOf << 10 << endl;
                fileOf << 1.1 << endl;
                fileOf << 'a' << endl;

                fileOf.close();
            } else {
                cerr << "Blad przy otwieraniu pliku!" << endl;
            }
        }
        break;
        case 11:
        {
            ifstream file ("kod.txt");
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    string processedLine;
                    for (int i = 0; i < line.length(); ++i) {
                        if (line[i] == '/' && i+1 < line.length() && line[i+1] == '/') {
                            break;
                        }
                        processedLine += line[i];
                    }
                    cout << processedLine << endl;
                }

                file.close();
            } else {
                cerr << "Blad przy otwieraniu pliku 'kod.txt'" << endl;
            }
        }
        break;
        case 12:
        {
            ifstream file ("kod.txt");
            if(file.is_open()){
                char c, nc;
                while(file.get(c)){
                    if(c == '/'){
                        nc = file.peek();
                        if(nc == '/')
                            file.ignore(numeric_limits<streamsize>::max(),'\n');
                        else
                            cout << c<<nc;
                    } else cout << c;
                }
            } else {
                cerr << "Blad przy otwieraniu pliku 'kod.txt'" << endl;
            }
        }
        break;
        case 2:
        {
            int o = 0, inp = 0, tries = 0;
            while(o != 21){
                cout << "POdawaj: ";
                try{
                    cin >> inp;
                    if(cin.fail())
                        throw TypeMissmatchError("int");
                    if(inp < 1)
                        throw WrongArgError();
                    if(o+inp > 21)
                        throw ArgOverflowError();
                    o += inp;
                    tries++;
                } catch(TypeMissmatchError& e){
                    e.error();
                    clearCin();
                } catch(WrongArgError& e){
                    e.error();
                } catch(ArgOverflowError& e){
                    e.error();
                    tries++;
                }
            }
            cout << "Got 21 within "<<tries<<" tries" << endl;
        }
        break;
        case 3:
        {
            int choice = 0;
            try {
                cout << "Podaj ścieżkę do pliku z danymi (dane.csv): ";
                string filename;
                cin >> filename;

                vector<Student> students;
                loadStudents(filename, students);

                while (choice != 7) {
                    cout << "\n1. Wyświetl książkę adresową\n"
                            << "2. Dodaj studenta\n"
                            << "3. Wyświetl osoby o podanym nazwisku\n"
                            << "4. Stwórz pliki k.csv oraz m.csv\n"
                            << "5. Wyświetl X pierwszych studentów\n"
                            << "6. Posortuj studentów według oceny\n"
                            << "7. Wyjście\n"
                            << "Wybierz opcję: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            for(auto it = students.begin(); it != students.end(); ++it){
                                it->show();
                            }
                            break;
                        case 2: {
                            int progress = 0;
                            string fName, lName, email;
                            char gender;
                            double grade;

                            // Input validation loop
                            while (progress < 5) {
                                try {
                                    switch(progress){
                                        case 0:
                                            cout << "Podaj imię: ";
                                            cin >> fName;
                                            if (!Student::isValidName(fName))
                                                throw ProgressError(progress,"Niepoprawne imię.");
                                            progress++;
                                            break;
                                        case 1:
                                            cout << "Podaj nazwisko: ";
                                            cin >> lName;
                                            if (!Student::isValidName(lName))
                                                throw ProgressError(progress,"Niepoprawne nazwisko.");
                                            progress++;
                                            break;
                                        case 2:
                                            cout << "Podaj płeć (K/M): ";
                                            cin >> gender;
                                            if (!Student::isValidGender(gender))
                                                throw ProgressError(progress,"Niepoprawna płeć.");
                                            progress++;
                                            break;
                                        case 3:
                                            cout << "Podaj ocenę: ";
                                            if (!(cin >> grade))
                                                throw ProgressError(progress,"Niepoprawna ocena.");
                                            progress++;
                                            break;
                                        case 4:
                                            clearCin();
                                            cout << "Podaj email (opcjonalnie): ";
                                            getline(cin, email);
                                            if (!email.empty() && !Student::isValidEmail(email))
                                                throw ProgressError(progress,"Niepoprawny email.");
                                            progress++;
                                            students.emplace_back(fName, lName, gender, grade, email);
                                            break;
                                    }
                                } catch (ProgressError& e) {
                                    e.error();
                                    clearCin();
                                }
                            }
                            break;
                        }
                        case 3: {
                            // Displaying students by last name
                            string searchLastName;
                            cout << "Podaj nazwisko do wyszukania: ";
                            cin >> searchLastName;

                            for (const auto& student : students) {
                                if (student.lastName == searchLastName) {
                                    student.show();
                                }
                            }
                            break;
                        }
                        case 4: {
                            saveToCSV(students,"k.csv",'K');
                            saveToCSV(students,"m.csv",'M');
                            break;
                        }
                        case 5: {
                            // Displaying first X students
                            int X;
                            cout << "Ilu pierwszych studentów chcesz wyświetlić? ";
                            cin >> X;

                            if (X > students.size()) {
                                cout << "Jest tylko " << students.size()
                                    << " studentów w bazie.\n";
                                break;
                            }

                            for(auto it = students.begin(); it != students.begin() + X; ++it)
                                it->show();
                            break;
                        }
                        case 6: {
                            sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                                return a.grade < b.grade;
                            });
                            break;
                        }
                        case 7:
                            saveToCSV(students, filename);
                            break;
                        default:
                            cout<< "Niepoprawny wybór. Spróbuj ponownie.\n";
                    }
                }

            } catch (FileError& e) {
                e.error();
            }
        }
        break;
        case 4:
        {
        }
        break;
        case 41:
        {
        }
        break;
        default:
        break;
        }
    }

    return 0;
}

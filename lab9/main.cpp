#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Error.h"

using namespace std;


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
                } catch(TypeMissmatchError e){
                    e.error();
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } catch(WrongArgError e){
                    e.error();
                } catch(ArgOverflowError e){
                    e.error();
                    tries++;
                }
            }
            cout << "Got 21 within "<<tries<<" tries" << endl;
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

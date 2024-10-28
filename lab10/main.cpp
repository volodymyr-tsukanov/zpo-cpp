#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <regex>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;


void print(char x){
    cout<<x<<"|";
}
char toUpper(char ch){
    if((ch>='a' and ch<='z'))
    return ch-32;
}

void testRegex(vector<string>& testSet, regex& rgx){
    for (auto it = testSet.begin(); it != testSet.end(); ++it) {
        cout << "'"<<*it<<"': "<<regex_match(*it, rgx) << endl;
    }
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
            // String Manipulation and Input/Output
            string line1 = "Programowanie";
            string line2("Programowanie");

            cout << "Podaj slowo: " << endl;
            cin >> line1;
            cin.clear();
            cin.ignore();

            cout << "Wczytane slowo: " << line1 << endl;
            getline(cin, line2);
            cout << "Zdanie: " << line2 << endl;

            if (line1 == line2)
                cout << "Napisy sa takie same" << endl;
            else
                cout << "Napisy roznia sie" << endl;

            line1 = line1 + " " + line2;

            cout << "Napis: " << line1 << endl;
            cout << "Druga litera: " << line1[1] << endl;

            cout << "Napis w for: " << endl;
            for (int i = 0; i < line1.length(); i++)
            {
                cout << line1[i];
            }
            cout << endl;

            line1.append(" i psa");
            cout << "Napis po append: " << line1 << endl;

            int ind = line1.find('a');
            cout << "Pierwsze wystapienie znaku 'a': " << ind << endl;
            ind = line1.find('a', 7);
            cout << "Pierwsze wystapienie znaku 'a' po 7 pozycji: " << ind << endl;
            ind = line1.find_last_not_of("kgtoa");
            cout << "Ostatnie wystepienie litery, ktora nie jest kgtoa: " << ind << endl;

            line2 = line1.substr(0, 3);
            cout << "Substr(0,3): " << line2 << endl;
            line1.insert(line1.begin(), '*');
            line1.push_back('*');

            cout << "Napis po insert i push_back: " << line1 << endl;
            for (string::iterator it = line1.begin(); it != line1.end(); it++)
                cout << *it;

            string::iterator del;
            del = line1.erase(line1.begin() + 0, line1.begin() + 5);

            cout << *del << endl;
            cout << "Napis po erase: " << line1 << endl;

            // Transformations and Algorithms
            cout << "Transform" << endl;
            transform(line1.begin(), line1.end(), line1.begin(), ::toupper);
            cout << line1 << endl;
            cout << "find" << endl;
            del = find(line1.begin(), line1.end(), 'K');
            if (del != line1.end())
            {
                cout << *del << endl;
            }
            cout << "for_each" << endl;
            for_each(line1.begin(), line1.end(), print);

            // String Case Conversion and Manipulation
            string line = "programowanie";
            cout << line << endl;
            to_upper(line);
            cout << "To_upper: " << line << endl;
            line = to_lower_copy(line);
            cout << "To_lower: " << line << endl;
            cout << "Erase_first: " << erase_first_copy(line, "o") << endl;
            cout << "Erase_all:" << erase_all_copy(line, "o") << endl;
            cout << "Replace_first: " << replace_first_copy(line, "p", "P") << endl;
            cout << "replace_all: " << replace_all_copy(line, "o", "-O-") << endl;
            vector<string> vec{"Programowanie", "w", "C++"};
            cout << "Join: " << join(vec, " ") << endl;

            string s = "\nProgramowanie w C++\n";
            cout << s << endl;
            cout << "Trim: _" << trim_copy(s) << "_" << endl;
            s = "---Programowanie w C++---";
            cout << s << endl;
            cout << "Trim_if is_any_of: " << trim_copy_if(s, is_any_of("-")) << endl;
            s = "123Programowanie w C++12";
            cout << s << endl;
            cout << "Trim if digit: " << trim_copy_if(s, is_digit()) << endl;
            s = "Programowanie w C++";
            cout << s << endl;
            cout << "Ends_with: " << ends_with(s, "C++") << endl;
            cout << "Contains: " << contains(s, "gram") << endl;
            s = "Programowanie w C++";
            vector<string> vec1;
            split(vec1, s, is_space());
            cout << "Zawartosc vectora: " << endl;
            for (int i = 0; i < vec1.size(); i++)
                cout << vec1[i] << endl;

            // Regex
            line = "Programowanie w C++";
            if (regex_match(line, regex("(Prog)(.*)")))
            {
                cout << "Znaleziono" << endl;
            }
            else
            {
                cout << "Nie znaleziono!" << endl;
            }
            regex regPattern("(Prog)(.*)");
            if (regex_match(line, regPattern))
            {
                cout << "Znaleziono" << endl;
            }
            else
            {
                cout << "Nie znaleziono!" << endl;
            }
            if (regex_match(line.begin(), line.end(), regPattern))
            {
                cout << "Znaleziono" << endl;
            }
            else
            {
                cout << "Nie znaleziono!" << endl;
            }
            smatch res;
            regPattern = "(Prog)(.*)";
            regex_match(line, res, regPattern);
            cout << "Regex_match:" << endl;
            cout << "Czy znaleziony? " << res.size() << endl;
            if (res.size() != 0)
            {
                cout << "Wzorzec: " << res[0] << " zostal znaleziony" << endl;
            }
            // Comparison of match and search
            string testLine = "***Programowanie w C++********";
            regex_match(testLine, res, regPattern);
            if (res.size() != 0)
            {
                cout << "Wzorzec: " << res[0] << " zostal znaleziony" << endl;
            }
            regex_search(testLine, res, regPattern);
            // Output results from regex_search
            cout << "Regex_search:" << endl;
            cout << "Liczba dopasowan:" << (res.size()) << endl;
            // Additional output details...
            for (int i = 0; i < res.size(); ++i)
            {
                // Output each subgroup...
                //...
            }
            // Replace example
            testLine = "***Programowanie w C++********";
            regPattern = "(C\\+{2})";
            testLine = regex_replace(testLine, regPattern, "Java");
        }
        break;
        case 1:
        {
            regex floatRegex("[+-]?[0-9]+\\.[0-9]+");

            vector<string> testCases {
                "+6.789",
                "-7.234",
                "3.14",
                "0.001",
                "-0.5",
                "+123.456",
                "123",         // Invalid
                "abc.123",     // Invalid
                "+.123",       // Invalid
                "-123."        // Invalid
            };

            cout << "Float reggiex:" << endl;
            testRegex(testCases, floatRegex);
        }
        break;
        case 2:
        {
            regex timeRegex("^(?:([01]\\d|2[0-3]):([0-5]\\d)(?::([0-5]\\d))?)?$");

            vector<string> times {
                "12:30",
                "23:59",
                "00:00",
                "15:45:30",
                "09:05:05",
                "24:00",      // Invalid
                "12:60",      // Invalid
                "12:30:60",   // Invalid
                "12:30:",     // Invalid
                "abc:def",    // Invalid
                "12:30:45"    // Valid
            };

            cout << "Testing time format:\n";
            testRegex(times, timeRegex);
        }
        break;
        case 3:
        {
            regex streetRegex("^[A-Za-zżźćńółęąśŻŹĆĄŚĘŁÓŃ ]+$");
            regex postalCodeRegex("^\\d{2}-\\d{3}$");
            regex houseNumberRegex("^\\d+[A-Za-z]?$");
            regex apartmentNumberRegex("^\\d+[A-Za-z]?$");

            vector<string> streets {"Aleja Jana Pawła II", "ulica 123", "Krakowska", "Wrocław"};
            vector<string> postalCodes {"12-345", "67-890", "12345", "12-3A"};
            vector<string> houseNumbers {"28", "28B", "100", "100C", "Abc"};
            vector<string> apartmentNumbers {"1", "2A", "3B", "4", "2abc", "bbc"};

            cout << "Testing streets:\n";
            testRegex(streets, streetRegex);

            cout << "\nTesting postal codes:\n";
            testRegex(postalCodes, postalCodeRegex);

            cout << "\nTesting house numbers:\n";
            testRegex(houseNumbers, houseNumberRegex);

            cout << "\nTesting apartment numbers:\n";
            testRegex(apartmentNumbers, apartmentNumberRegex);
        }
        break;
        case 4:
        {
        }
        break;
        case 5:
        {
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }
}

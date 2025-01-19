#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;


class Student {
public:
    string firstName;
    string lastName;
    char gender;
    double grade;
    string email;


    Student(const string& fName, const string& lName, char gen, double grd, const string& mail = "") : firstName(fName), lastName(lName), gender(gen), grade(grd), email(mail) {}
    Student(const string& student){
        string s;
        stringstream ss (student);

        getline(ss,firstName,';');
        getline(ss,lastName,';');
        getline(ss,s,';');
        gender = s[0];
        getline(ss,s,';');
        grade = stod(s);
        getline(ss,email,';');
    }


    void show() const {
        cout << left << setw(20) << firstName
                  << setw(20) << lastName
                  << setw(10) << gender
                  << setw(10) << grade
                  << setw(30) << email << endl;
    }


    static bool isValidEmail(const string& email) {
        return email.find('@') != string::npos;
    }
    static bool isValidName(const string& name) {
        if (name.empty()) {
            return false;
        }

        char fc = name[0];
        if ((fc >= 'A' && fc <= 'Z') ||
            (fc == 'Ą') || (fc == 'Ć') || (fc == 'Ę') ||
            (fc == 'Ł') || (fc == 'Ń') || (fc == 'Ó') ||
            (fc == 'Ś') || (fc == 'Ź') || (fc == 'Ż')) {
            return true;
        }

        return false;
    }
    static bool isValidGender(char gender) {
        return gender == 'K' || gender == 'M';
    }
};

#endif // STUDENT_H

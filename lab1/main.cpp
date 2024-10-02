#include <iostream>
#include "Person.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;


int main()
{
    int n = 3;
    /*l1
    cout << endl << "Obiekty klasy Person" << endl;
    Person o1("Grazyna", "Nowak", 45);
    o1.showInfoPerson();
    cout << "Czy pelnoletnia?: " << o1.is_18() << endl;
    o1.setAge(16);

    cout << endl << "Obiekty klasy Teacher" << endl;
    Teacher n1("Barbara", "Kowalska", 56, 30, "Phd");
    n1.showInfoTeacher();
    cout << "Czy ma Phd?: " << n1.is_Phd() << endl;
    n1.setAge(34);*/

    /*l2
    Person p1[3];
    Person* p2;
    Person* p3[3];
    Person** p4;

    for (int i = 0; i < 3; i++)
    {
        p1[i].init("Anna", "Nowak", 20 + i);
        p1[i].showInfoPerson();
    }

    p2 = new Person[3];

    for (int i = 0; i < 3; i++)
    {
        p2[i].init("Ola", "Adamek", 20 + i);
        p2[i].showInfoPerson();
    }

    for (int i = 0; i < 3; i++)
    {
        p3[i] = new Person("Kasia", "Kowalska", 20 + i);
        p3[i]->showInfoPerson();
    }

    p4 = new Person*[3];

    for (int i = 0; i < 3; i++)
    {
        p4[i] = new Person("Pawel", "Wojcik", 20 + i);
        p4[i]->showInfoPerson();
    }

    for (int i = 0; i < 3; i++) {
        delete p3[i];
    }

    for (int i = 0; i < 3; i++) {
        delete p4[i];
    }

    delete[] p4;*/

    /*z1.1*/
    printf("Static-static\n");
    Student s_s[n];
    for (int i = 0; i < n; i++){
        s_s[i].init("std", "tst", i+1, "index");
        s_s[i].showInfoStudent();
    }

    printf("\n\nDynamic-static\n");
    Student* d_s = new Student[n];
    for (int i = 0; i < n; i++){
        d_s[i].init("std", "tst", i+1, "index");
        d_s[i].showInfoStudent();
    }

    printf("\n\nStatic-dynamic\n");
    Student* s_d[n];
    for (int i = 0; i < n; i++){
        s_d[i] = new Student("std", "tst", i+1, "index");
        s_d[i] -> showInfoStudent();
    }

    printf("\n\Dynamic-dynamic\n");
    Student** d_d = new Student*[n];
    for (int i = 0; i < n; i++){
        d_d[i] = new Student("std", "tst", i+1, "index");
        d_d[i] -> showInfoStudent();
    }

    //Cleanup
    for (int i = 0; i < n; i++) {
        delete d_d[i];
        delete s_d[i];
    }
    delete[] d_d;


    /*z1.2*/

    return 0;
}

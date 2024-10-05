#include <iostream>
#include <string>
#include "Figure.h"
#include "Square.h"
#include "Circle.h"
#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;


struct Emplyees{
    int n;
    Employee** tab;
};


void howManyEarnLessThanMeanBonus(Emplyees emps, int bonus=50){
    float m = 0.0;  //calculate mean
    for(int i = 0; i < emps.n; i++){
        Employee* e = emps.tab[i];
        m += e->calculateBonus(bonus);
    }
    m /= emps.n;

    printf("bonus < %.2fgroszy\n", m);
    for(int i = 0; i < emps.n; i++){
        Employee* e = emps.tab[i];
        float eBonus = e->calculateBonus(bonus);
        if(eBonus < m){
            cout << "  "<<eBonus<<"gr <= ";
            e->show();
        }
    }
}

void whoWorkMoreThan5Years(Emplyees emps){
    cout << "alive > 5:" << endl;
    for(int i = 0; i < emps.n; i++){
        Employee* e = emps.tab[i];

        if(e->getExperience() > 5){
            cout << "  ";
            e->show();
        }
    }
}


int main()
{
    /*1
    Figure* f1 = new Square(4);
    Figure* f2 = new Circle(2);

    f1->calculateArea();
    f1->show();

    f2->calculateArea();
    f2->show();

    delete f1;
    delete f2;*/

    /*zad2.1
    Figure* tab[3];
    tab[0]=new Square(4);
    tab[1]=new Square(2);
    tab[2]=new Circle(5);
    for(int i=0;i<3;i++)
    {
        tab[i]->calculateArea();
        tab[i]->calculatePerimeter();
        tab[i]->show();
        delete tab[i];
    }*/

    /*zad2.2*/
    Emplyees emps;
    emps.n = 10;
    emps.tab = new Employee*[emps.n];
    for(int i = 0; i < emps.n-1; i++){
        string sname = "Adamski-"+to_string(i+1);
        emps.tab[i] = new Developer(sname, 18+i, i, 99.98);
    }
    emps.tab[emps.n-1] = new TeamLeader("Evovska", 67, 47, 319190.99);

    whoWorkMoreThan5Years(emps);
    cout << "\n\n\n";
    howManyEarnLessThanMeanBonus(emps, 40);

    //cleanup
    for(int i = 0; i < emps.n; i++) delete emps.tab[i];
    delete[] emps.tab;

    return 0;
}

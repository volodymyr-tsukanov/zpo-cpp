#include <iostream>
#include "Adding.h"
#include "Student.h"
#include "Array.h"

using namespace std;


template <typename T>
void showAll(T* tab[], int n)
{
    for(int i=0;i<n;i++) tab[i]->show();
}

/*template <typename T>
void checkType(T a)
{
    T val=numeric_limits<T>::max();
    cout<<val<<endl;
}*/

template <typename T>
T* findMin(T* tab[], int n){
    T* m = tab[0];
    for(int i = 1; i < n; i++){
        if(tab[i] < m) m = tab[i];
    }
    return m;
}


int main()
{
    int n = 6;
    /*1
    Adding<int> a1(5);
    a1.add(6);
    a1.show();

    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();*/

    /*2
    Student<float> s(5,"Ala");
    s.showMark();
    Student<int> s1(5,"Ala");
    s1.showMark();
    Student<string> s2(5,"Ala");
    s2.showMark();*/

    /*3
    Adding<int>* arrAdd[3];
    for(int i=0;i<3;i++)
    {
        arrAdd[i]=new Adding<int>(i);
    }
    showAll(arrAdd,3);

    Student<string>* arrStu[2];
    for(int i=0;i<3;i++){
        arrStu[i]=new Student<string>(i+2,"Ala");
    }
    showAll(arrStu,3);

    for(int i=0; i<3; i++)
        delete arrAdd[i];

    for(int i=0; i<2; i++)
        delete arrStu[i];*/

    /*4
    checkType<int>(3);*/

    /*zad3.2
    Adding<int>* arrAdd[n];
    for(int i=0;i<n;i++)
        arrAdd[i]=new Adding<int>(i-9);
    findMin(arrAdd, n)->show();*/

    /*zad3.3 */
    Array<int> arr_i = Array<int>(8);
    Array<double> arr_d = Array<double>(7);
    Array<string> arr_s = Array<string>(9);

    for(int i = 0; i < n; i++){
        arr_i.add(i);
        arr_d.add(i+0.28);
        arr_s.add("["+to_string(i+6)+"]");
    }

    arr_i.show();   arr_d.show();   arr_s.show();

    cout << arr_i.getMax()<<"\t ; \t"<<arr_d.getMax()<<"\t ; \t"<<arr_s.getMax() << endl;

    arr_i.sortAsc();    arr_d.sortAsc();   arr_s.sortAsc();
    cout << "\n\nafter sorting acs: " << endl;
    arr_i.show();   arr_d.show();   arr_s.show();

    return 0;
}

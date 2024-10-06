#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Even.h"
#include "Student.h"
#include "Compare.h"
#include "City.h"

using namespace std;


template <typename T>
void show(T &con)
{
    for(typename T::iterator it=con.begin( ); it!=con.end( ); it++)
        cout<<*it<<" ";
    cout<<endl;
}

void print(int& el)
{
    cout<<el<<"***";
}
void add10(int &el)
{
    el=el+10;
}
bool isEven(int x)
{
    if (x%2 == 0)
        return true;
    else
        return false;
}

void showMark(Student &s)
{
    cout << s.getMark() << " ";
}

void randRange(int &i, mt19937 eng){
    uniform_int_distribution<> distr(-100, 100);
    i = distr(eng);
}

void showCities(vector<City> c){
    for(int i = 0; i < c.size(); i++){
        City rc = c[i];
        rc.show_city();
    }
}
void statistic(vector <City> c){
    for(int i = 0; i < c.size(); i++){
        City rc = c[i];
        cout << rc.getCityName()<<" => adults: "<<rc.adults()<<"; girls: "<<rc.women() << endl;
        rc.postal_codes();
    }
}
void the_most(vector<City> c, int mode){

}
funkcja szuka danych określonych przez
parametr mode (tryb) oraz wyświetla informacje na konsolę. Każdy z podpunktów
powinien zostać zrealizowany w oddzielnej funkcji. Tryb:
1. Miasto, w którym jest najwięcej różnych kodów pocztowych;
2. Miasto, w którym mieszka najmniej mieszkańców;


int main()
{
    random_device rd;
    mt19937 eng (rd());
    uniform_int_distribution<> distr(10, 100);
    uniform_int_distribution<> distr2(-100, 100);
    /*1
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout<<"Operator[]"<<endl;
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    cout<<"At"<<endl;
    for(int i=0; i<vec.size(); i++)
        cout<<vec.at(i)<<" ";
    cout<<endl;

    cout<<"Iterator: "<<endl;
    vector <int>::iterator it;
    for(it=vec.begin(); it != vec.end(); it++ )
        cout <<*it<<" ";
    cout<<endl;

    cout<<"begin() "<< *vec.begin()<<" front() "
        <<vec.front()<<endl;
    cout<<"end() "<< *(vec.end()-1)<<" back() "
        <<vec.back()<<endl;

    show(vec);
    vec.pop_back();
    show(vec);
    vec.erase(vec.begin()+1,vec.begin()+2);
    show(vec);
    vec.insert(vec.begin()+1,100);
    show(vec);
    vec.clear();
    show(vec);

    vector<float>vec2(5,8.2);
    show(vec2);
    vec2.push_back(3.1);
    show(vec2);*/

    /*2
    vector<int>num= {3,6,3,8,9,1,3};
    show(num);
    sort(num.begin(),num.end());
    show(num);
    cout<<"binary search"<<endl;
    cout<<binary_search(num.begin(),num.end(),3)<<endl;
    cout<<"count"<<endl;
    cout<<count(num.begin(),num.end(),3)<<endl;
    cout<<"reverse"<<endl;
    reverse(num.begin(),num.begin()+4);
    show(num);
    cout<<"random_shuffle"<<endl;
    random_shuffle(num.begin(),num.end());
    show(num);
    cout<<"max element"<<endl;
    cout<<*max_element(num.begin(),num.end())<<endl;
    cout<<"merge"<<endl;
    vector<int>num2(4,6);
    vector<int>res(num.size()+num2.size());
    sort(num.begin(),num.end());
    merge(num.begin(),num.end(),num2.begin(),
          num2.end(),res.begin());
    show(res);

    for_each(num.begin(),num.end(),print);
    for_each(num.begin(),num.end(),add10);
    cout<<endl;
    for_each(num.begin(),num.end(),print);
    cout<<endl;
    cout<<count_if(num.begin(),num.end(),isEven);*/

    /*3
    vector<int> num3={2, -6, 7, 3, 0, 8, -9, -2};
    for_each(num3.begin(),num3.end(),print);
    int howMany=count_if(num3.begin( ), num3.end( ),
    bind2nd(greater<int>( ),0));
    cout<<endl<<"wersja1: wartosc > 0 "<<howMany<<endl;
    greater<int> f;
    howMany=count_if(distr2num3.begin( ), num3.end( ),
    bind2nd(f,0));
    cout<<"wersja2: wartosc > 0 "<<howMany<<endl;
    cout<<"Przed sortowaniem"<<endl;
    for_each(num3.begin(),num3.end(),print);
    sort(num3.begin( ), num3.end( ), greater<int>());
    cout<<endl<<"Po sortowaniu"<<endl;
    for_each(num3.begin(),num3.end(),print);*/

    /*4
    vector<int>num4= {3,6,3,8,9,1,3};
    for_each(num4.begin(),num4.end(),print);
    cout<<endl;
    cout<<count_if(num4.begin(),num4.end(),isEven)<<endl;
    cout<<count_if(num4.begin(),num4.end(),Even(2))<<endl;*/

    /*5
    vector<Student>st;
    st.push_back(Student(1,"Ala"));
    st.push_back(Student(5,"Ola"));
    st.push_back(Student(2,"Piotr"));
    for_each(st.begin(),st.end(),showMark);
    cout<<endl;
    sort(st.begin(),st.end(),Compare());
    for_each(st.begin(),st.end(),showMark);*/

    /*zad4.2
    int n = distr(eng);
    vector<int> l1 (n);
    for(int i = 0; i < n; i++){
        l1[i] = distr2(eng);
    }
//    for_each(l1.begin(), l1.end(), [eng](int &i){
//            randRange(i, eng);
//         });
    sort(l1.begin(), l1.end(), greater<int>());
    show(l1);*/

    /*zad4.3 */
    vector<City> cts;

    return 0;
}

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>
#include <boost/mpl/int.hpp>
#include <boost/bind.hpp>
//#include <boost/>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "Person.h"
#include "Contact.h"
#include "Contacts.h"

using namespace boost::multi_index;
using namespace std;

typedef multi_index_container<Person, indexed_by<
    hashed_non_unique<member<Person, string, &Person::name>>,
    hashed_non_unique<member<Person, int, &Person::age>>
>> person_multi;
typedef person_multi::nth_index<0>::type name_type;
typedef person_multi::nth_index<1>::type age_type;
typedef multi_index_container<Person,indexed_by<
ordered_non_unique<member<Person,string,&Person::name>>,
ordered_non_unique<member<Person,int,&Person::age>>,
random_access<> >> person_multi_2;
typedef person_multi_2::nth_index<0>::type name_type2;
typedef person_multi_2::nth_index<1>::type age_type2;


class Print
{
    public:
    template <typename T>
    void operator()(T t)
    {
        cout <<"\t"<< t <<endl;
    }
};

class Operation
{
public:
    int operator()(int a, int b)
    {
        return a - b;
    }

    int operator()(char a)
    {
        return (int)a - 32;
    }
};


int addition(int a, int b)
{
    return a + b;
}
void firstArgMod(int& x, int y)
{
    x = x + y;
}

void printF(int x)
{
    cout << x << " ";
}

void contatination(int i1, int i2)
{
    cout << i1 << i2 << endl;
}


void UlaToUrszula(Person& x) {
    x.name="Urszula";
}
void AlaToAlicja(Person& x) {
    if(x.name=="Ala")
    x.name="Alicja";
}


void procT(const double& t, double* sum, vector<double>* sortedV){
    *sum +=t;
    sortedV->push_back(t);
}
void lessAvgT(const double& t, const double avg){
    if(t < avg) cout << t <<" ";
}
void betweenRangeT(const double& t, double rangeStart, double rangeEnd){
    if(rangeEnd < rangeStart) swap(rangeStart, rangeEnd);
    if(t > rangeStart && t < rangeEnd) cout << t<<" ";
}
void positioveT(const double& t){
    if(t > 0) cout << t <<" ";
}
template <typename T>
void zad63(vector<T>& v){
    int n = v.size(), idx = 0;
    double avg = 0.0, mean = 0.0;
    vector<double> vw;

    for_each(v.begin(),v.end(),boost::bind(procT,_1,&avg,&vw));
    avg /= n;

    sort(vw.begin(), vw.end(), greater_equal<double>());   //niemalejaco
    mean = vw[n/2];

    cout << "avg: "<<avg<<" | mean: "<<mean << endl;
    cout << "less avg: ";
    for_each(v.begin(),v.end(),boost::bind(lessAvgT,_1,avg));
    cout << "\nbetween avg and mean: ";
    for_each(v.begin(),v.end(),boost::bind(betweenRangeT,_1,avg,mean));
    cout << "\npositive😀: ";
    for_each(v.begin(),v.end(),boost::bind(positioveT,_1));
}

template <typename V>
void ileFusion(V& v){
    map<string,int> mp;

    boost::fusion::for_each(v, [&mp](const auto& val) {
        string type_name (typeid(val).name());
        auto tp = mp.find(type_name);
        if(tp == mp.end()){  //no such typename => add
            mp.insert(pair<string,int>(type_name,1));
        } else {
            tp->second++;
        }
    });

    for(auto it = mp.begin(); it != mp.end(); ++it){
        cout << it->first<<" = "<<it->second << endl;
    }
}


int main()
{
    int zadN = 1;
    printf("n?: ");
    cin >> zadN;

    switch(zadN){
    case 1:
    {
        //1
        person_multi persons;

        persons.insert({"Ala", 40});
        persons.insert({"Piotr", 10});
        persons.insert({"Ola", 18});
        persons.insert({"Ala", 46});
        persons.insert({"Ula", 46});

        age_type &age_index = persons.get<1>();
        cout << "Liczba osob z wiekiem 18 lat: " << age_index.count(18) << endl;

        for (name_type::iterator it = persons.get<0>().begin(); it != persons.get<0>().end(); ++it)
            it->show();
        for(age_type::iterator it=persons.get<1>().begin();
        it != persons.get<1>().end(); ++it)
        it->show();

        auto &age_indexx = persons.get<1>();
        auto it = age_indexx.find(46);
        cout << "Znaleziona osoba, ktora ma 46 lat: " << it->name << endl;
        cout << "Liczba osob o imieniu Ala: " << persons.count("Ala") << endl;
        cout << "Liczba osob o imieniu Ala: " << persons.get<0>().count("Ala") << endl;


        //2
        auto &name_indexx = persons.get<0>();
        auto itt = name_indexx.find("Ula");
        name_indexx.modify(itt, boost::bind(UlaToUrszula,_1));


        //3
        cout << "Przed modyfikacja: "<<endl;
        vector<name_type::iterator> elements;
        for(name_type::iterator it=persons.get<0>().begin();
        it != persons.get<0>().end(); ++it)
        {
        it->show();
        elements.push_back(it);
        }
        //for (int i = 0; i<elements.size();i++)
        //name_indexx.modify(elements[i],boost::bind(AlaToAlicja,_1));
        cout << "Po modyfikacji"<<endl;
        for(name_type::iterator it=persons.get<0>().begin();

        it != persons.get<0>().end(); ++it)
        {
            it->show();
        }


        //4
        person_multi_2 persons2;
        persons2.get<2>().push_back({"Ala", 40});
        persons2.get<2>().push_back({"Ala", 45});
        persons2.get<2>().push_back({"Piotr", 10});
        persons2.get<2>().push_back({"Ola", 18});

        persons2.get<2>().push_back({"Aga", 46});
        persons2.get<2>().push_back({"Ula", 46});

        auto &name_indexx2 = persons2.get<0>();
        auto iterStart = name_indexx2.equal_range("Ala");
        auto iterStop = name_indexx2.equal_range("Piotr");

        cout <<"przedzial od Ala do Piotr - wersja 1"<<endl;

        for (name_type2::iterator it=iterStart.first; it != iterStop.second; ++it)
            it->show();

        auto from = name_indexx2.lower_bound("Ala");
        auto to = name_indexx2.upper_bound("Piotr");

        cout <<"przedzial od Ala do Piotr - wersja 2"<<endl;
        for (auto it=from; it != to; ++it)
            it->show();


        //5
        auto &rand_indexx = persons2.get<2>();
        cout << rand_indexx[0].name <<endl;


        //6 fusion
        boost::fusion::vector<int, string, bool, double> vec{10, "C++", true, 3.14};
        cout << "Trzeci element w vec:"<<boost::fusion::at<boost::mpl::int_<2>>(vec) <<endl;
        auto vec2 = push_back(vec, 'M');
        cout <<"Liczba elementow w wvec: "<< size(vec) <<endl;
        cout << "Liczba elementow w vec2: "<<size(vec2) <<endl;
        cout << "Pierwszy element w vec2: "<<front(vec2) <<endl;
        cout << "Ostatni element w vec2: "<<back(vec2) <<endl;
        cout<<"Cala zawartosc vec2: "<<endl;
        boost::fusion::for_each(vec2,Print());
        auto itvStart = begin(vec);
        auto itvStop = end(vec);
        cout<<"Pierwszy element: "<<*itvStart<<endl;
        cout<<"Drugi element: "<<*next(itvStart)<<endl;
        cout<<"Trzeci element: "<<*advance<boost::mpl::int_<2>>(itvStart)<<endl;
    }
    break;
    case 11:
    {
        cout << "vec: " << endl;

        vector<int> vec = {1, 2, 3, 4, 5};
        vector<int>::iterator iter1 = vec.begin();
        vector<int>::iterator iter2 = vec.end();

        for_each(iter1, iter2, boost::bind(printF, _1));

        cout << endl << "vec - kazdy element zwiekszony o 5: ";
        for_each(iter1, iter2, boost::bind(firstArgMod, _1, 5));
        for_each(iter1, iter2, boost::bind(printF, _1));

        int count = std::count_if(vec.begin(), vec.end(),
            boost::bind(std::logical_and<bool>(),
            boost::bind(std::greater<int>(), _1, 8),
            boost::bind(std::less_equal<int>(), _1, 10)));

        cout << endl << "vec - 8<Elementy<=10: " << count << endl;

        cout << addition(1, 2) << endl;

        int res = boost::bind(addition, _1, _2)(1, 2);
        cout << res << endl;

        int i1 = 1, i2 = 2;
        boost::bind(contatination, _2, _1)(i1, i2);

        Operation ff;

        int x = 1024;
        //cout << "Funktor: " << bind<int>(ff, _1, _1)(x) << endl;

        char y = 'a';
        //cout << "Funktor: " << bind<char>(ff, _1)(y) << endl;
    }
    case 2:
    {
        Contacts cnts;
        cnts.addContact({10,"nm","sn", "birch", "38478512"});
        cnts.addContact({19,"nm5","sn", "birch", "47478512"});
        cnts.addContact({17,"n4","sn8", "oak", "58478512"});
        cnts.addContact({29,"nm3","sn9", "pine", "45478512"});
        cnts.show(); cout << "\n\n";
        cout << "FbPh 47*: "<<cnts.findByPhone("47478512")->name << endl<<endl;
        cout << "FbSt birch: "<<cnts.findAllByStreet("birch") << endl<<endl;
        cout << "FbAgRange [19-30): "<<cnts.findAllByAgeRange(19,30) << endl<<endl;
        cout << "CAgedFull: "<<cnts.countAllAgedFull() << endl<<endl;
        cout << "UqSurnamed: "<<cnts.countUniqueSurnamed() << endl<<endl;
        cout << "ChSt birch: "<<cnts.changeStreet("birch", "barszcz") <<endl<<endl;
        cnts.rmvContact("58478512");
        cnts.show();
    }
    break;
    case 3:
    {
        cout << "(int)" << endl;
        vector<int> vi = {7,1,2,6,3,4,5,-87};
        zad63<int>(vi);
        cout << "\n\n(float)";
        vector<float> vf = {7.0,1.0,2.0,6.0,3.0,4.0,5.0,-86.9999};
        zad63<float>(vf);
        cout << "\n\n(bool)";
        vector<bool> vb = {true,false,false,true,true};
        zad63<bool>(vb);
        cout << "\n\n(char)";
        vector<char> vc = {'c','p','p','+'};
        zad63<char>(vc);
        /*cout << "\n\n(string)";
        vector<string> vs = {"true","false","was","ist","das"};
        zad63<string>(vs);*/
    }
    case 4:
    {
        boost::fusion::vector<bool,int,char,float,double> v (true,0,'s',9.87,8976.9953231);
        auto v2 = push_back(v, 876);
        auto v3 = push_back(v2, 554);
        auto v4 = push_back(v3, 'i');
        ileFusion(v4);
    }
    break;
    default:
    break;
    }

    return 0;
}

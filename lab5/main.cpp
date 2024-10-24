#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include "Dictionary.h"

using namespace std;


template<typename T>
void show(set<T> st)
{
    for (auto itr = st.begin(); itr != st.end(); itr++)
    {
        cout << *itr << " | ";
    }
    cout << endl;
}
void show(map<char, int> mp){
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first<<" = "<<it->second << endl;
    }
}

pair<set<int>::iterator, bool> findDuplicate(vector<int>& v, int& sum){
    pair<set<int>::iterator, bool> result;
    set<int> st;
    sum = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        auto res = st.insert(*it);
        if(res.second)
            sum += *(res.first);
        else{
            sum -= *(res.first);
            result = res;
        }
    }
    return result;
}

template<typename T>
void showSetIntersection(set<T>& st1, set<T>& st2){
    set<T> result;
    set_difference(st1.begin(),st1.end(), st2.begin(),st2.end(),
            insert_iterator(result, result.begin()));
    set_difference(st2.begin(),st2.end(), st1.begin(),st1.end(),
            insert_iterator(result, result.end()));
    show(result);
}

char findDifference(string& s1, string& s2){
    char result = (char)0;
    map<char, int> mp;
    if(s1.length() > s2.length())
        swap(s1, s2);
    for(int i = 0; i < s1.length(); i++){
        auto k = mp.find(s1[i]);
        if(k == mp.end()){
            mp.insert(pair<char, int>(s1[i], 1));
        } else {
            k->second++;
        }
    }
    //show(mp);
    for(int i = 0; i < s2.length(); i++){
        auto k = mp.find(s2[i]);
        if(k == mp.end()){
            result = s2[i];
            break;
        } else {
            k->second--;
        }
    }
    return result;
}


int main()
{
    int zadN = 1;
    while(zadN != 0){
        printf("n?: ");
        cin >> zadN;

        switch(zadN){
        case 1:
        {
            int sum = 2;
            vector<int> v1 = {1, 2, 3, 99, 4, 99};
            auto res = findDuplicate(v1, sum);
            cout << "sum = "<<sum<<"; duplicate is "<<*(res.first) << endl;
        }
        break;
        case 2:
        {
            set<int> st1 = {1, 2, 3, 4, 5};
            set<int> st2 = {4, 5, 1, 9, 0};
            showSetIntersection(st1, st2);
        }
        break;
        case 3:
        {
            string s1 = "i - boss", s2 = "s bo-s ";
            cout << "different char: '"<<findDifference(s1, s2)<<"'" << endl;
        }
        break;
        case 4:
        {
            Dictionary dic;
            dic.addWord("sun", "słońce");
            dic.addWord("duck", "kaczka");
            dic.addWord("dick", "imię się nie tłumaczy 😈");
            dic.addWord("son", "syn");
            dic.addWord("sus", "?؟ ");
            dic.addWord("sos", "pomocy");
            dic.addWord("arm", "ręka");
            cout << "Alphabetically" << endl;
            dic.print(true);
            dic.translate("sun");
            dic.rmvWord("dick");
            dic.print();
        }
        break;
        default:
        break;
        }

        cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
    }

    return 0;
}

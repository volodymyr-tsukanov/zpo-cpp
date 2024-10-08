#include <iostream>
#include <vector>
#include <set>

using namespace std;


pair<set<int>::iterator, bool> findDuplicate(vector<int>& v, int& sum){
    pair<set<int>::iterator, bool> result;
    set<int> s;
    sum = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        auto res = s.insert(*it);
        if(res.second)
            sum += *(res.first);
        else{
            sum -= *(res.first);
            result = res;
        }
    }
    return result;
}

int main()
{
    /*zad5.1 */
    int sum = 2;
    vector<int> v1 = {1, 2, 3, 99, 4, 99};
    auto res = findDuplicate(v1, sum);
    cout << "sum = "<<sum<<"; duplicate is "<<*(res.first) << endl;

    return 0;
}

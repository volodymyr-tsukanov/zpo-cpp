#include "Dictionary.h"


Dictionary::Dictionary()
{
}


string Dictionary::translate(string word)
{
    return words.find(word)->second;
}


bool Dictionary::addWord(string word, string translation)
{
    return words.insert(pair<string, string>(word, translation)).second;
}
bool Dictionary::updWord(string word, string translation)
{
    //return words.insert_or_assign(word, translation).second;
    bool updated = words.find(word) != words.end();
    words[word] = translation;
    return updated;
}
void Dictionary::rmvWord(string word)
{
    auto w = words.find(word);
    if(w != words.end())
        words.erase(w);
}


void Dictionary::print()
{
    for(auto it = words.begin(); it != words.end(); it++){
        cout << " "<<it->first<<" <=> "<<it->second << endl;
    }
}

void Dictionary::print(bool translation_alphabetically)
{
    vector<string> outv;
    for(auto it = words.begin(); it != words.end(); it++)
        outv.push_back(it->second + " <=> " + it->first);

    sort(outv.begin(), outv.end(), [](const string& s1, const string& s2){
        return s1[0] > s2[0];
    });

    for(auto it = outv.begin(); it != outv.end(); it++)
        cout << *it << endl;
}

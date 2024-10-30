#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


class Dictionary
{
private:
    map<string, string> words;

public:
    Dictionary();

    string translate(string word);

    bool addWord(string word, string translation);
    bool updWord(string word, string translation);
    void rmvWord(string word);

    void print();
    void print(bool translation_alphabetically);
};

#endif // DICTIONARY_H

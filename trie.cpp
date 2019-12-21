#include <string>
#include <iostream>
#include <vector>
#include "trie.h"
using namespace std;

int main(void)
{
    int cad;
    cin >> cad;
    vector <string> cadenas(cad), res;
    for(int i = 0 ; i < cad ; i++)
        cin >> cadenas[i];
    string pref;
    cin >> pref;
    trieNode *root = getTrieNode();
    for(auto cad : cadenas)
        insert(root, cad);
    res = searchWordinString(root, pref);
    for(auto a : res)
        cout << a << " ";
    cout << "\n";
}

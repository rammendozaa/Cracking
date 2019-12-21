#include <string>
#include <iostream>
using namespace std;
const int tamABC = 26;
struct trieNode
{
    trieNode *children[tamABC];
    bool isWord;
};

trieNode *getTrieNode()
{
    trieNode *root = new trieNode;
    root -> isWord = false;
    for(int i = 0 ; i < tamABC ; i++)
        root -> children[i] = NULL;
    return root;
}

void insert(trieNode *root, string palabra)
{
    trieNode *auxRoot = root;
    int tamS = palabra.length();
    for(int i = 0 ; i < tamS ; i++)
    {
        int indice = palabra[i] - 'a';
        if(!auxRoot -> children[indice])
            auxRoot -> children[indice] = getTrieNode();
        auxRoot = auxRoot -> children[indice];
    }
    auxRoot -> isWord = true;
}

void prefixHelper(trieNode *root, vector <string> &sal, string word)
{
    if(!root)
        return;
    if(root && root -> isWord)
        sal.push_back(word);
    for(int i = 0 ; i < tamABC ; i++)
    {
        trieNode *auxR = root;
        string auxS = word;
        if(auxR -> children[i])
        {
            auxS += (i + 'a');
            auxR = auxR -> children[i];
            prefixHelper(auxR, sal, auxS);
        }
    }
}

void wordsPrefix(trieNode *root, string prefix, vector <string> &sal)
{
    trieNode *auxRoot = root;
    int tamS = prefix.length();
    for(int i = 0 ; i < tamS ; i++)
    {
        int index = prefix[i] - 'a';
        if(!auxRoot -> children[index])
            return;
        auxRoot = auxRoot -> children[index];
    }
    prefixHelper(auxRoot, sal, prefix);
}

/*
trieNode* searchPart(trieNode *root, string palabra)
{
    trieNode *auxRoot = root;
    int tamS = palabra.length();
    for(int i = 0 ; i < tamS ; i++)
    {
        int index = palabra[i] - 'a';
        if(!auxRoot -> children[index])
            return NULL;
        auxRoot = auxRoot -> children[index];
    }
    return auxRoot;
}

*/

trieNode* searchWord(trieNode *root, string palabra)
{
    trieNode *auxRoot = root;
    int tamS = palabra.length();
    for(int i = 0 ; i < tamS ; i++)
    {
        int index = palabra[i] - 'a';
        if(!auxRoot -> children[index])
            return NULL;
        auxRoot = auxRoot -> children[index];
    }
    //    return (auxRoot && auxRoot -> isWord);
    //  could return a bool to see if it exists
    return auxRoot;
}

//Daily Coding Problem 22
vector <string> searchWordinString(trieNode *root, string palabra)
{
    trieNode *auxRoot = root;
    int tamS = palabra.length();
    vector <string> res;
    string auxS = "";
    for(int i = 0 ; i < tamS ; i++)
    {
        int index = palabra[i] - 'a';
        if(!auxRoot -> children[index])
            return vector <string> {};
        if(auxRoot -> children[index] && auxRoot -> children[index] -> isWord)
        {
            auxS += palabra[i];
            res.push_back(auxS);
            auxS = "";
            auxRoot = root;
        }
        else
        {
            auxRoot = auxRoot -> children[index];
            auxS += palabra[i];
        }
//        auxRoot = auxRoot -> children[index];
    }
    return (auxS.length() > 0) ? vector <string>{} : res;
    //    return (auxRoot && auxRoot -> isWord);
    //  could return a bool to see if it exists
}

bool decide(trieNode *root, string s)
{
    int place, tam = s.length();
    for(int i = 0 ; i < tam ; i++)
    {
        if(s[i] == '?')
        {
            place = i;
            break;
        }
    }
    string first, second;
    first = s.substr(0, place);
    second = s.substr(place + 1, tam - place);
    cout << first << " " << second << "\n";
    trieNode *aux = searchWord(root, first);
    if(aux)
    {
        for(int i = 0 ; i < tamABC ; i++)
            if(aux -> children[i])
                if(searchWord(aux -> children[i], second))
                    return true;
        return false;
    }
    return false;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include "linkedList.h"
using namespace std;

int main(void)
{
    LinkedList<int> *lista[10];
    for(int i = 0 ; i < 10 ; i++)
    {
        lista[i] = new LinkedList<int> ();
        lista[i] -> push_back(i * i);
        /*
        aux.first = "("+ to_string(i) +" + 1) =";
        aux.second = i + 1;
        lista[i] -> push_back(empare("("+ to_string(i) +" + 1) =", (i + 1)));
        */
    }
    for(int i = 0 ; i < 10 ; i++)
        cout << lista[i] -> cabezaW() << "\n";



    /*
    LinkedList<int> *lista1 = new LinkedList<int> ();
    LinkedList<int> *lista2 = new LinkedList<int> ();
    int tam1, tam2, aux1, aux2;
    cout << "tam1\n" << "tam2\n";
    cin >> tam1 >> tam2;
    for(int i = 0 ; i < tam1 ; i++)
    {
        cin >> aux1;
        lista1 -> push_back(aux1);
    }
    for(int i = 0 ; i < tam2 ; i++)
    {
        cin >> aux2;
        lista2 -> push_back(aux2);
    }
    cout << lista1 -> sumDigitsRev(lista2) << "\n";
    LinkedList<int> *lista3 = new  LinkedList <int> ();
    lista3 -> copiar(lista2);
    lista3 -> imprimir();
    */
}

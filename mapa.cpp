#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "mapa.h"
using namespace std;

int main(void)
{
    mapa <string, int> *soyMapa = new mapa<string, int> ();
    soyMapa -> insertar("hola", 4);
    int res = soyMapa -> rescatar("hola");
    cout << res << "\n";
    cout << "Hola\n";
    return 0;
}

#include "hashList.h"
using namespace std;

#define  MAX_TABLE 500000
template <class key, class value> struct mapa
{
    public:
        hashList<key,value> *tabla[MAX_TABLE / 100];
        mapa()
        {
            for(int i = 0 ; i < (MAX_TABLE / 100) ; i++)
                tabla[i] = new hashList<key, value> ();
        }

        ~mapa()
        {
            for(int i = 0 ; i < (MAX_TABLE / 100) ; i++)
                tabla[i] = NULL;
        }

        unsigned int hashFunc(key llave)
        {
            unsigned int h = 0;
            for(auto a : llave)
                h = h * 101 + (unsigned int)a;
            return h % (MAX_TABLE / 100);
        }

        void insertar(key llave, value valor)
        {
            int hashResult = hashFunc(llave);
            if(tabla[hashResult] -> existe(llave))
                tabla[hashResult] -> actualizar(llave, valor);
            else
                tabla[hashResult] -> push_back(empare(llave, valor));
        }

        value rescatar(key llave)
        {
            int hashResult = hashFunc(llave);
            value res = tabla[hashResult] -> encontrar(llave);
            return res;
        }

        void borrar(key llave)
        {
            int hashResult = hashFunc(llave);
            tabla[hashResult] -> quitar(llave);
        }
};

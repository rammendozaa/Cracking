using namespace std;
template <class T> struct LinkedList
{
    public:
        struct node{
            node *next;
            T data;
            node(T val)
            {
                data = val;
                next = NULL;
            }
        };
        node *cola, *cabeza;
        int tam;
        LinkedList()
        {
            tam = 0;
            cola = NULL;
            cabeza = NULL;
        }

        bool esVacia()
        {
            return tam == 0;
        }

        int taman()
        {
            return tam;
        }

        T colaW()
        {
            if(esVacia())
                cout << "Can't\n";
            else
                return cola -> data;
        }

        T cabezaW()
        {
            if(esVacia())
                cout << "Can't\n";
            else
                return cabeza -> data;
        }

        void push_back(T val)
        {
            if(esVacia())
            {
                node *nuevo = new node(val);
                cabeza = nuevo;
                cola = nuevo;
            }
            else
            {
                node *nuevo = new node(val);
                cola -> next = nuevo;
                cola = nuevo;
            }
            tam++;
        }

        void push_front(T val)
        {
            if(esVacia())
            {
                node *nuevo = new node(val);
                cabeza = nuevo;
                cola = nuevo;
            }
            else
            {
                node *nuevo = new node(val);
                nuevo -> next = cabeza;
                cabeza = nuevo;
            }
            tam++;
        }

        void pop_back()
        {
            if(esVacia())
                cout << "Can't\n";
            else if(tam == 1)
            {
                cabeza = NULL;
                cola = NULL;
            }
            else
            {
                node *ult = cabeza -> next;
                node *penult = cabeza;
                while(ult -> next)
                {
                    penult = penult -> next;
                    ult = ult -> next;
                }
                penult -> next = NULL;
                cola = penult;
                tam--;
            }
        }

        void pop_front()
        {
            if(esVacia())
                cout << "Can't\n";
            else
            {
                cabeza = cabeza -> next;
                tam--;
            }
        }

        bool existe(T valor)
        {
            if(esVacia())
                return false;
            node *aux = cabeza;
            while(aux)
            {
                if(aux -> data == valor)
                    return true;
                aux = aux -> next;
            }
            return false;
        }

        void cambiar(T valor, int pos)
        {
            node *aux = cabeza;
            if(pos < 0 || pos >= tam)
                return;
            int ite = 0;
            while(ite < pos)
            {
                ite++;
                aux = aux -> next;
            }
            aux -> data = valor;
        }

        void quitar(int pos)
        {
            int ite = 0;
            node *aux = cabeza;
            node *ultAux = cabeza -> next;
            if(esVacia())
                return;
            if(pos == 0)
                cabeza = cabeza -> next;
            else if(pos == 1)
                cabeza -> next = cabeza -> next -> next;
            else
            {
                while(ite < pos - 1)
                {
                    ite++;
                    aux = aux -> next;
                    ultAux = ultAux -> next;
                }
                aux -> next = ultAux -> next;
                if(pos == tam - 1)
                    cola = aux;
            }
        }

        void poner(T valor, int pos)
        {
            int ite = 0;
            if(esVacia())
                return;
            else if(pos < 0 || pos >= tam)
                return;
            else
            {
                node *nuevo = new node(valor);
                node *aux = cabeza;
                while(ite < pos - 1)
                {
                    aux = aux -> next;
                    ite++;
                }
                nuevo -> next = aux -> next;
                aux -> next = nuevo;
            }
        }

        void imprimir()
        {
            if(esVacia())
            {
                cout << "eh";
            }
            node *aux = cabeza;
            while(aux)
            {
                cout << aux -> data << " ";
                aux = aux -> next;
            }
            cout << "\n";
        }

        void sortList()
        {
            vector <T> aqui;
            node *aux = cabeza, *otro;
            while(aux)
            {
                aqui.push_back(aux -> data);
                aux = aux -> next;
            }
            sort(aqui.begin(), aqui.end());
            node *here = new node(aqui[0]);
            cabeza = here;
            otro = cabeza;
            for(int i = 1 ; i < aqui.size() ; i++)
            {
                here = new node(aqui[i]);
                otro -> next = here;
                otro = otro -> next;
            }
        }

        void vaciar()
        {
            while(!esVacia())
                pop_back();
        }

        void removeDup()
        {
            node *aux = cabeza, *auxD = cabeza -> next;
            map <T, int> nodos;
            nodos[cabeza -> data] = 1;
            while(auxD)
            {
                if(nodos[auxD -> data] > 0)
                {
                    aux -> next = auxD -> next;
                }
                else
                {
                    nodos[auxD -> data]++;
                    aux = auxD;
                }
                auxD = auxD -> next;
            }
        }

        void mergeOrdered(const LinkedList<T> *uno, const LinkedList<T> *dos)
        {
            vaciar();
            node *unoA, *unoB, *dosA, *dosB, *head;
            unoA = uno -> cabeza;
            dosA = dos -> cabeza;
            LinkedList<int> *nueva = new LinkedList<int> ();
            while(unoA && dosA)
            {
                if(unoA -> data < dosA -> data)
                {
                    nueva -> push_back(unoA -> data);
                    unoA = unoA -> next;
                }
                else
                {
                    nueva -> push_back(dosA -> data);
                    dosA = dosA -> next;
                }
            }
            if(unoA)
            {
                while(unoA)
                {
                    nueva -> push_back(unoA -> data);
                    unoA = unoA -> next;
                }
            }
            else if(dosA)
            {
                while(dosA)
                {
                    nueva -> push_back(dosA -> data);
                    dosA = dosA -> next;
                }
            }
            node *auxF = nueva -> cabeza;
            while(auxF)
            {
                push_back(auxF -> data);
                auxF = auxF -> next;
            }
        }

        void copiar(LinkedList <T> *uno)
        {
            vaciar();
            node *aux = uno -> cabeza;
            while(aux)
            {
                push_back(aux -> data);
                aux = aux -> next;
            }
        }

        void reverse()
        {
            node *aux = cabeza -> next, *ite = new node(cabeza -> data);
            while(aux)
            {
                node *nuevo = new node(aux -> data);
                nuevo -> next = ite;
                ite = nuevo;
                aux = aux -> next;
            }
            cabeza = ite;
        }

        int sumDigits(LinkedList <T> *uno)
        {
            int suma = 0, carry = 0, prod = 1, sumaInt = 0;
            node *aux1 = cabeza, *aux2 = uno -> cabeza;
            while(aux1 && aux2)
            {
                sumaInt = carry + (aux1 -> data + aux2 -> data);
                if(sumaInt >= 10)
                {
                    carry = sumaInt / 10;
                    sumaInt -= 10;
                }
                else
                    carry = 0;
                suma += (sumaInt * prod);
                prod *= 10;
                aux1 = aux1 -> next;
                aux2 = aux2 -> next;
            }
            if(aux1)
            {
                while(aux1)
                {
                    if(carry > 0)
                    {
                        suma += ((carry + aux1 -> data) * prod);
                        carry = 0;
                    }
                    else
                        suma += ((aux1 -> data) * prod);
                    prod *= 10;
                    aux1 = aux1 -> next;
                }
            }
            else if(aux2)
            {
                while(aux2)
                {
                    if(carry > 0)
                    {
                        suma += ((carry + aux2 -> data) * prod);
                        carry = 0;
                    }
                    else
                        suma += ((aux2 -> data) * prod);
                    prod *= 10;
                    aux2 = aux2 -> next;
                }
            }
            cout << carry << "\n";
            if(carry > 0)
                suma += carry * prod;
            return suma;
        }

        int sumDigitsRev(LinkedList <T> *uno)
        {
            reverse();
            uno -> reverse();
            int res = sumDigits(uno);
            reverse();
            uno -> reverse();
            return res;
        }

        T find(T buscado)
        {
            node *aux = cabeza;
            while(aux)
            {
                if(aux -> data == buscado)
                    return buscado;
                aux = aux -> next;
            }
            return NULL;
        }

};

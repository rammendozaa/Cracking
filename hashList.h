using namespace std;

template <class fType, class sType> struct par
{
    fType first;
    sType second;

};

template <class fType, class sType>
par<fType, sType> empare(fType prim, sType seg)
{
    par <fType, sType> aux;
    aux.first = prim;
    aux.second = seg;
    return aux;
}

template<class fType, class sType>
struct hashList
{

        struct node{
            node *next;
            par <fType, sType> data;
            node(par<fType, sType> val)
            {
                data = val;
                next = NULL;
            }
        };
        node *cola, *cabeza;
        int tam;
        hashList()
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

        par<fType, sType> colaW()
        {
            if(esVacia())
                cout << "Can't\n";
            else
                return cola -> data;
        }

        par<fType, sType> cabezaW()
        {
            if(esVacia())
                cout << "Can't\n";
            else
                return cabeza -> data;
        }

        void push_back(par<fType, sType> val)
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

        void push_front(par<fType, sType> val)
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
                cola = penult;
                penult -> next = NULL;
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

        sType encontrar(fType buscado)
        {
            node *aux = cabeza;
            while(aux)
            {
                if((aux -> data).first == buscado)
                    return (aux -> data).second;
                aux = aux -> next;
            }
            return NULL;
        }

        void quitar(fType buscado)
        {
            node *aux = cabeza;
            while(aux)
            {
                if((aux -> data).first == buscado)
                {
                    (aux -> data).first = ((aux -> next) -> data).first;
                    (aux -> data).second = ((aux -> next) -> data).second;
                    aux -> next = aux -> next -> next;
                    return;
                }
                aux = aux -> next;
            }
            return;
        }

        void actualizar(fType buscado, sType nuevoValor)
        {
            node *aux = cabeza;
            while(aux)
            {
                if((aux -> data).first == buscado)
                {
                    (aux -> data).second = nuevoValor;
                    return;
                }
                aux = aux -> next;
            }
        }


        bool existe(fType valor)
        {
            if(esVacia())
                return false;
            node *aux = cabeza;
            while(aux)
            {
                if((aux -> data).first == valor)
                    return true;
                aux = aux -> next;
            }
            return false;
        }

};

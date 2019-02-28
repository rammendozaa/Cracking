template <class T>
struct Queue
{
    public:
        struct node{
            T data;
            node *next;
            node *before;
            node(T valor)
            {
                data = valor;
                next = NULL;
                before = NULL;
            }
        };
        node *entra, *sale;
        int tam;
        Queue()
        {
            tam = 0;
            entra = NULL;
            sale = NULL;
        }

        bool esVacia()
        {
            return tam == 0;
        }

        int size()
        {
            return tam;
        }

        void pushBack(T val)
        {
            node *aux = new node(val);
            if(esVacia())
            {
                entra = aux;
                sale = aux;
                tam++;
            }
            else
            {
                aux -> next = entra;
                aux -> next -> before = aux;
                entra = aux;
                tam++;
            }
        }

        void pushFront(T val)
        {
            node *aux = new node(val);
            if(esVacia())
            {
                entra = aux;
                sale = aux;
                tam++;
            }
            else
            {
                aux -> before = sale;
                aux -> before -> next = aux;
                sale = aux;
                tam++;
            }
        }

        T front()
        {
            return sale -> data;
        }

        T back()
        {
            return entra -> data;
        }

        void popFront()
        {
            sale = sale -> before;
            tam--;
        }

        void popBack()
        {
            entra = entra -> next;
            tam--;
        }
};

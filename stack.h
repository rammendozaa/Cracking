template <class T>
struct Stack
{
    public:
        struct node{
            T data;
            node *next;
            node(T valor)
            {
                data = valor;
                next = NULL;
            }
        };
        node *tope = NULL;
        int tam;
        Stack()
        {
            tam = 0;
            tope = NULL;
        }

        bool esVacia()
        {
            return tam == 0;
        }

        int size()
        {
            return tam;
        }

        T top()
        {
            return tope -> data;
        }

        void pop()
        {
            if(!esVacia())
            {
                tope = tope -> next;
                tam--;
            }
        }

        void push(T value)
        {
            node *nuevo = new node(value);
            if(esVacia())
            {
                tope = nuevo;
                tam++;
            }
            else
            {
                nuevo -> next = tope;
                tope = nuevo;
                tam++;
            }
        }

        void vaciar()
        {
            while(!esVacia())
                pop();
        }

};

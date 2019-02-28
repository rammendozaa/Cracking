using namespace std;

template <class T>
struct binarySTree{
    struct node{
        T valor;
        node *left;
        node *right;
        node(T value)
        {
            valor = value;
            left = NULL;
            right = NULL;
        }
    };
    node *root;
    binarySTree()
    {
        root = NULL;
    }

    insert(T entrada, node *raiz)
    {
        if(raiz == NULL)
            raiz = new node(entrada);
        else
        {
            if(entrada < raiz -> valor)
            {
                if(raiz -> left != NULL)
                    insert(entrada, raiz -> left);
                else
                {
                    raiz -> left = new node(entrada);
                    raiz -> left -> valor = entrada;
                }
            }
            else
            {
                if(raiz -> right != NULL)
                    insert(entrada, raiz -> right);
                else
                {
                    raiz -> right = new node(entrada);
                    raiz -> right -> valor = entrada;
                }
            }
        }
    }

    T search(T buscar, node *raiz)
    {
        if(raiz != NULL)
        {
            if(buscar == raiz -> value)
                return buscar;
            else if(buscar < raiz -> value)
                search(buscar, raiz -> left);
            else
                search(buscar, raiz -> right);
        }
        else
            return NULL;
    }

    void inorder(node *raiz)

};

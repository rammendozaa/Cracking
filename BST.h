using namespace std;

template <class T>
struct treeNode{
        T valor;
        treeNode *left;
        treeNode *right;
        treeNode(T value)
        {
            valor = value;
            left = NULL;
            right = NULL;
        }
};
template <class T>
treeNode <T> *insert(T entrada, treeNode <T> *raiz)
{
    if(!raiz)
    {
        treeNode <T> *aux = new treeNode <T>(entrada);
        return aux;
    }
    if(raiz -> valor < entrada)
        raiz -> right = insert(entrada, raiz -> right);
    else
        raiz -> left = insert(entrada, raiz -> left);
    return raiz;
}

template <class T>
bool search(T buscado, treeNode <T> *raiz)
{
    bool existe, leftT = false, rightT = false;
    if(raiz != NULL)
    {
        if(raiz -> valor == buscado)
            return true;
        else if(raiz -> valor < buscado)
            rightT = search(buscado, raiz -> right);
        else
            leftT = search(buscado, raiz -> left);
        return leftT || rightT;
    }
}

template <class T>
void toArray(treeNode <T> *raiz, vector <T> &res)
{
    if(!raiz)
    {
        res.push_back(NULL);
        return;
    }
    res.push_back(raiz -> valor);
    toArray(raiz -> left, res);
    toArray(raiz -> right, res);
}

template <class T>
treeNode<T> *toTree(int &i, vector <T> &res)
{
    if(!res[i])
    {
        i++;
        return NULL;
    }
    if(i == res.size())
        return NULL;
    treeNode<T> *raiz = new treeNode<T> (res[i]);
    i++;
    raiz -> left = toTree(i, res);
    raiz -> right = toTree(i, res);
    return raiz;
}

treeNode <int> *deserialize(string &entrada, int &i)
{
    i++;
    if(i >= entrada.size())
        return NULL;
    string auxS = "";
    while(entrada[i] != ' ')
    {
        auxS += entrada[i];
        i++;
    }
    if(auxS[0] == '-')
        return NULL;
    int este = stoi(auxS);
    treeNode <int> *nuevo = new treeNode <int>(este);
    nuevo -> left = deserialize(entrada, i);
    nuevo -> right = deserialize(entrada, i);
    return nuevo;
}

template <class T>
void serialize(treeNode <T> *root, string &salida)
{
    if(!root)
    {
        salida += " -";
        return;
    }
    string auxS = to_string(root -> valor);
    salida += (" " + auxS);
    serialize(root -> left, salida);
    serialize(root -> right, salida);
}


template <class T>
vector <T> treeToSimpleArray(treeNode <T> *raiz)
{
    if(!raiz)
        return vector <T>{};
    vector <vector <int> > niveles(40);
    vector <int> auxNivel;
    int maxLevel = 1;
    niveles[0].push_back(raiz -> valor);
    queue <pair<treeNode <T>*, int> > q;
    q.push(pair<treeNode <T>*, int> (raiz, 1));
    pair <treeNode<T>*, int> auxN;
    while(!q.empty())
    {
        auxN = q.front();
        q.pop();
        if(auxN.first -> left)
        {
            niveles[auxN.second].push_back(auxN.first -> left -> valor);
            q.push( pair<treeNode <T>*, int> (auxN.first -> left, auxN.second + 1));
            maxLevel = max(maxLevel, auxN.second);
        }
        else
            niveles[auxN.second].push_back(NULL);
        if(auxN.first -> right)
        {
            niveles[auxN.second].push_back(auxN.first -> right -> valor);
            q.push( pair <treeNode <T>*, int> (auxN.first -> right, auxN.second + 1));
            maxLevel = max(maxLevel, auxN.second);
        }
        else
            niveles[auxN.second].push_back(NULL);
    }
    maxLevel++;
    niveles.resize(maxLevel);
    for(auto a : niveles)
        for(auto b : a)
            auxNivel.push_back(b);
    return auxNivel;
}


template <class T>
treeNode <T> *arrayToTree(int i, vector <T> &entrada)
{
    if(i >= entrada.size())
        return NULL;
    if(!entrada[i])
        return NULL;
    treeNode <T> *raiz = new treeNode <T> (entrada[i]);
    raiz -> left = arrayToTree(2 * i + 1, entrada);
    raiz -> right = arrayToTree(2 * i + 2, entrada);
    return raiz;
}

template <class T>
treeNode<T> *crearDeVectorOrdenado(vector <T> &entrada, int low, int high)
{
    if(high >= low)
    {
        int mid = (low + high) / 2;
        treeNode<T> *raiz = new treeNode<T>(entrada[mid]);
        raiz -> right = crearDeVectorOrdenado(entrada, mid + 1, high);
        raiz -> left = crearDeVectorOrdenado(entrada, low, mid - 1);
        return raiz;
    }
    else
        return NULL;
}

template <class T>
bool helperUni(treeNode <T> *raiz, T value)
{
    if(!raiz)
        return true;
    if(raiz -> valor != value)
        return false;
    return helperUni(raiz -> left , value) && helperUni(raiz -> right, value);
}

template <class T>
bool checkUni(treeNode <T> *raiz)
{
    if(!raiz)
        return true;
    int val = raiz -> valor;
    return helperUni(raiz -> left, val) && helperUni(raiz -> right, val);
}

template <class T>
int howManyUni(treeNode <T> *raiz)
{
    if(!raiz)
        return 0;
    int total = (checkUni(raiz)) ? 1 : 0;
    total += (howManyUni(raiz -> left) + howManyUni(raiz -> right));
    return total;
}

template <class T>
pair <treeNode <T>*, int> helperDeep(treeNode <T> *raiz, int level)
{
    if(!raiz -> left && !raiz -> right)
        return pair <treeNode <T>*, int> (raiz, level);
    if(!raiz -> left)
        return helperDeep(raiz -> right, level + 1);
    if(!raiz -> right)
        return helperDeep(raiz -> left, level + 1);
    pair <treeNode <T>*, int> left, right;
    left = helperDeep(raiz -> left, level + 1);
    right = helperDeep(raiz -> right, level + 1);
    if(left.second > right.second)
        return left;
    else
        return right;
}

template <class T>
pair <treeNode <T>*, int> deepestLevelNode(treeNode <T> *raiz)
{
    if(!raiz)
        return pair <treeNode <T> *, int> (NULL, 0);
    return helperDeep(raiz, 1);
}

template <class T>
bool isMirror(treeNode <T> *rootUno, treeNode <T> *rootDos)
{
    if(!rootUno && !rootDos)
        return true;
    if((!rootUno && rootDos) || (rootUno && !rootDos))
        return false;
    if(rootUno -> valor != rootDos -> valor)
        return false;
    return true && isMirror(rootUno -> left, rootDos -> right) && isMirror(rootUno -> right, rootDos -> left);
}

template <class T>
int numberNodes(treeNode <T> *raiz)
{
    if(!raiz)
        return 0;
    return 1 + numberNodes(raiz -> left) + numberNodes(raiz -> right);
}

template <class T>
void inorder(treeNode <T> *raiz)
{
    if(!raiz)
        return;
    inorder(raiz -> left);
    cout << raiz -> valor << " ";
    inorder(raiz -> right);
}

template <class T>
void postOrder(treeNode <T> *raiz)
{
    if(!raiz)
        return;
    postOrder(raiz -> left);
    postOrder(raiz -> right);
    cout << raiz -> valor << " ";
}

template <class T>
void preOrder(treeNode <T> *raiz)
{
    if(!raiz)
        return;
    cout << raiz -> valor << " ";
    preOrder(raiz -> left);
    preOrder(raiz -> right);
}

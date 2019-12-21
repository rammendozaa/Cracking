//criba de eratostenes 1 a n
//los primos están inicializados en 0
vector <int> Criba(int n)
{
    int raiz = sqrt(n);
    vector <int> criba = (n + 1);
    for(int = 4 ; i < = raiz ; i += 2)
        criba[i] = 2;
    for(int i = 3 ; i <= raiz ; i += 2)
        if(!criba[i])
            for(int j = i * i ; j <= n ; j += i)
                if(!criba[j])
                    criba[j] = i;
}

//divisores de cada numero 1 a n
vector <int> divisores(int n)
{
    vector <int> divi(n + 1);
    for(int i = 1 ; i <= n ; i++)
        for(int j = i ; j <= n ; j += i)
            divi[j]++;
    return divi;
}

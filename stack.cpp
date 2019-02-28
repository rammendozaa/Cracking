#include <iostream>
#include <vector>
#include <algorithm>
#include "stack.h"
using namespace std;

int main(void)
{
    Stack<int> *stacka1 = new Stack<int> ();
    Stack<int> *stacka2 = new Stack<int> ();
    int entrada;
    while(cin >> entrada)
        stacka1 -> push(entrada);
    while(!stacka1 -> esVacia())
    {
        cout << stacka1 -> top() << " ";
        stacka1 -> pop();
    }
}

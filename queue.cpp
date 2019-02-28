#include <iostream>
#include "queue.h"
using namespace std;

int main(void)
{
    Queue<int> *kiu = new Queue<int>();
    kiu -> pushBack(1);
    kiu -> pushBack(2);
    kiu -> pushBack(3);
    kiu -> pushBack(4);
    kiu -> pushFront(0);
    kiu -> pushFront(-1);
    kiu -> pushFront(-2);
    kiu -> pushFront(-3);
    while(!kiu -> esVacia())
    {
        cout << kiu -> back() << " ";
        kiu -> popBack();
    }






}

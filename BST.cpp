#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include "BST.h"
using namespace std;

int main(void)
{
    treeNode <int> *root = new treeNode <int>(2);
    /*
    root -> left = new treeNode <int>(3);
    root -> left -> left = new treeNode <int>(3);
    root -> left -> right = new treeNode <int>(3);
    root -> left -> left -> left = new treeNode <int>(3);
    root -> left -> left -> right =  new treeNode <int>(3);
    root -> left -> right -> left =  new treeNode <int>(2);
    root -> left -> right -> left -> left =  new treeNode <int>(11);
    root -> left -> right -> left -> right =  new treeNode <int>(2);
    root -> left -> right -> right =  new treeNode <int>(8);
    root -> right = new treeNode <int>(4);
    root -> right -> left = new treeNode <int>(5);
    root -> right -> right = new treeNode <int>(6);
    root -> right -> left -> left = new treeNode <int>(5);
    root -> right -> left -> right =  new treeNode <int>(5);
    root -> right -> right -> left =  new treeNode <int>(6);
    root -> right -> right -> right =  new treeNode <int>(6);
    root -> right -> right -> right -> left =  new treeNode <int>(6);
    root -> right -> right -> right -> right =  new treeNode <int>(10);
    */
    /*
    root -> left = new treeNode <int>(3);
    root -> right = new treeNode <int> (4);
    root -> left -> left = new treeNode <int> (7);
    root -> left -> right = new treeNode <int> (9);
    */

    root -> left = new treeNode <int>(1);
    root -> right = new treeNode <int>(7);
    root -> right -> left = new treeNode <int>(4);
    root -> right -> right = new treeNode <int>(10);
    root -> right -> left -> left = new treeNode <int>(3);
    root -> right -> left -> right = new treeNode <int>(6);

    /*
    root -> left = new treeNode <int>(3);
    root -> right = new treeNode <int>(8);
    root -> left -> left = new treeNode <int>(5);
    root -> left -> right = new treeNode <int>(7);
    root -> left -> left -> left = new treeNode <int>(11);
    root -> left -> right -> right = new treeNode <int>(12);
    root -> right -> left = new treeNode <int>(10);
    root -> right -> right = new treeNode <int>(12);
    */
    /*
    inorder(root);
    cout << "\n";
    pair <treeNode <int>*, int> deepest = deepestLevelNode(root);
    cout << deepest.first -> valor << " " << deepest.second << "\n";
    */

    //works
    //cout << numberNodes(root) << "\n";
    /*
    //works
    cout << howManyUni(root -> right -> right) << "\n";

    // - using vector 2*i
    vector <int> treeArray;
    treeArray = treeToSimpleArray(root);
    for(auto a : treeArray)
        cout << a << " ";
    cout << "\n";
    int i = 0;
    treeNode <int> *nuevo = arrayToTree(i, treeArray);
    inorder(nuevo);
    cout << "\n";
    */


    /*
    //works - using string
    string treeString = "";
    serialize(root, treeString);
    cout << treeString << "\n";
    int i = 0;
    treeNode <int> *newTree = deserialize(treeString, i);
    inorder(newTree);
    cout << "\n";
    */


    /*
    //works - using vector no 2*i
    vector <int> treeArray;
    toArray(root, treeArray);
    for(auto a : treeArray)
        cout << a << " ";
    cout << "\n";
    int i = 0;
    treeNode <int> *newTree = toTree(i, treeArray);
    inorder(newTree);
    cout << "\n";
    */

    treeNode <int> *nuevo = findLeastCommonAncestor(root, 4, 9);
    cout << nuevo -> valor << endl;

}

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node() : data(0), left(nullptr), right(nullptr) {}
    node(int x) : data(x), left(nullptr), right(nullptr) {}
    node(int x, node *leftptr) : data(x), left(leftptr), right(nullptr) {}
    node(int x, node *leftptr, node *rightptr) : data(x), left(leftptr), right(rightptr) {}
};

int main()
{

    cout << endl;
    return 0;
}
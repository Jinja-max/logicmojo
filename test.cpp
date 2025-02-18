#include <bits/stdc++.h>
using namespace std;

int hashFunction(string s)
{

    int hash = 0;

    for (int i = 0; i < s.length(); i++)
    {

        hash += (i % 2) * (i + 1) * (s[i] - 'a' + 1);
    }

    return hash;
}

int main()
{
    cout << hashFunction("wrsxmvdx") << endl
         << hashFunction("quwydsry");
    cout << endl;
    return 0;
}
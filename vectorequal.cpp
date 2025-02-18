#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> h = {4, 3, 43, 3};
    vector<int> k{4, 3, 4};
    k = h;
    for (auto i : k)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
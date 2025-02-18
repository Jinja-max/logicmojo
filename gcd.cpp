#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b % a == 0)
        return a;
    int res = gcd(b % a, a);
    return res;
}

int main()
{
    cout << gcd(8, 12);
    cout << endl;
    return 0;
}
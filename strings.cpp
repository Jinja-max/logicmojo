#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "we have 6 months still";

    for (char c : str)
        cout << c << " ";
    cout << str.substr(0, 0);
    // string multiplication by integer
    string freq = "ab";
    freq += 'c';
    cout << freq;
    string freqstr = string(3, 'd');

    cout << endl
         << freqstr << endl;
    cout << endl;
    return 0;
}
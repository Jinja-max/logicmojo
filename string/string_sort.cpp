#include <bits/stdc++.h>
using namespace std;

int main()
{
    // checking if sort() works for strings
    string a = "yeshwanth";
    vector<string> s = {"abc", "ghi", "def", "acd"};
    sort(a.begin(), a.end());
    cout << a << endl;
    sort(s.begin(), s.end());
    for (auto i : s)
        cout << i << " ";
    cout << endl;
    return 0;
}
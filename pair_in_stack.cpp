#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<pair<char, int>> st;
    st.push(make_pair('(', 3));
    st.push(make_pair(')', 4));
    auto t = st.top();
    cout << endl
         << t.first << "," << t.second << endl;
    cout << endl;
    return 0;
}
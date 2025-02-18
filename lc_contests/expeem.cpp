#include <bits/stdc++.h>
using namespace std;

int pro(int x, int y)
{
    if (x % 2 == 0)
        return x * y;
    else
        return x + y;
}

int up(int x, int y)
{
    int res = pro(x, y);

    return res / 2;
}

// int cal(int num)

int main()
{
    string str = "Hello, world!";
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
        st.push(str[i]);
    string rev = "";
    while (!st.empty())
    {
        rev += st.top();
        st.pop();
    }
    cout << rev << endl;
    return 0;
}
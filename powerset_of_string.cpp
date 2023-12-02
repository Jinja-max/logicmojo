#include <bits/stdc++.h>
using namespace std;

vector<string> powerSet(string s)
{
    int l = s.length();
    vector<string> res;
    int sub = 1 << l;
    for (int i = 0; i < sub; i++)
    {
        if (i == 0)
            res.push_back("");
        else
        {
            string t = "";
            int k = 0;
            int m = i;
            while (m != 0 && k < l)
            {
                if (m & 1 == 1)
                    t += s[k];
                m = m >> 1;
                k++;
            }
            res.push_back(t);
        }
    }
    return res;
}

int main()
{
    string s = "abc";
    vector<string> res = powerSet(s);
    for (auto i : res)
        cout << i << " ";
    // cout<<(2>>1)<<endl;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string lastNonEmptyString(string s)
{
    string temp = "///";
    while (s != "")
    {
        unordered_map<char, int> map;
        temp.clear();
        temp = s;
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s[i]] != 1)
            {
                map[s[i]]++;
                s.erase(i, i);
            }
        }
    }
    return temp;
}

int main()
{
    string temp = lastNonEmptyString("aabcbbca");
    cout << temp;
    cout << endl;
    return 0;
}
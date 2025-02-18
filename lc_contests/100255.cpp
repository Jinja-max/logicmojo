#include <bits/stdc++.h>
using namespace std;

int recursive(string &s, int &k, int i, int j, unordered_map<char, int> &mp)
{
    cout << i << " " << j << endl;
    if (i >= s.length())
        return 0;
    if (abs(mp[s[i]] - mp[s[j]]) <= k)
    {
        if (j == s.length() - 1)
            return recursive(s, k, i + 1, 0, mp);
        return recursive(s, k, i, j + 1, mp);
    }
    mp[s[i]]--;
    int a = 0;
    if (j == s.length() - 1)
        a = 1 + recursive(s, k, i + 1, 0, mp);
    else
        a = 1 + recursive(s, k, i, j + 1, mp);
    mp[s[i]]++;
    mp[s[j]]--;
    int b = 0;
    if (j == s.length() - 1)
        b = 1 + recursive(s, k, i + 1, 0, mp);
    else
        b = 1 + recursive(s, k, i, j + 1, mp);
    return min(a, b);
}

int minimumDeletions(string word, int k)
{
    unordered_map<char, int> mp;
    for (auto i : word)
        mp[i]++;
    return recursive(word, k, 0, 0, mp);
}

int main()
{
    cout << minimumDeletions("aabcaba", 0);
    cout << endl;
    return 0;
}
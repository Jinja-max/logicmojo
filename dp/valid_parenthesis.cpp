#include <bits/stdc++.h>
using namespace std;

int memoize(string s, int open, int i, vector<vector<int>> &dp)
{
    if (open < 0)
        return 0;
    if (i >= s.length())
    {
        if (open == 0)
            return 1;
        else
            return 0;
    }
    if (dp[open][i] != -1)
        return dp[open][i];
    if (s[i] == '(')
        return dp[open][i] = memoize(s, open + 1, i + 1, dp);
    else if (s[i] == ')')
        return dp[open][i] = memoize(s, open - 1, i + 1, dp);

    else
        return dp[open][i] = memoize(s, open + 1, i + 1, dp) || memoize(s, open - 1, i + 1, dp) || memoize(s, open, i + 1, dp);
}

bool checkValidString(string s)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(s.length(), -1));
    return memoize(s, 0, 0, dp);
}

int main()
{
    string s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    cout << checkValidString(s) << endl;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &price, int &max, int temp, int rodLen)
{
    if (rodLen == 0)
    {
        if (temp > max)
            max = temp;
        return;
    }
    for (int i = 1; i <= rodLen; i++)
    {
        solve(price, max, temp + price[i], rodLen - i);
    }
}

int rodCutting(vector<int> &price, int rodLen)
{
    int max = 0;
    int temp = 0;
    solve(price, max, temp, rodLen);
    return max;
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int max = rodCutting(price, 4);
    cout << max << endl;
    cout << endl;
    return 0;
}
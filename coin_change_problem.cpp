#include <bits/stdc++.h>
using namespace std;

// brue force approach -1
void solve(vector<int> &coins, int &size, int amount, int &res, int temp)
{
    if (amount == 0)
    {
        if (temp < res)
            res = temp;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (coins[i] <= amount)
            solve(coins, size, amount - coins[i], res, temp + 1);
    }
}

int coinChange(vector<int> &coins, int amount)
{
    int size = coins.size();
    int res = INT_MAX;
    solve(coins, size, amount, res, 0);
    if (res == INT_MAX)
        return -1;
    return res;
}

// brute force another type of code
int coinChange2(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= amount)
        {
            int sub_path = coinChange2(coins, amount - coins[i]);
            if (sub_path + 1 < res)
                res = sub_path + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> coins{1, 2, 5};
    int amount = 11;
    cout << coinChange2(coins, amount);
    cout << endl;
    return 0;
}

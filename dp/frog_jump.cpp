#include <bits/stdc++.h>
using namespace std;

/*void solve(int curr, int height[], int n, int &min, int energy)
{
}*/

// using memoization( note - first try using brute force recursion)
int minEnergy(int height[], int n, int dp[])
{
    if (n == 2)
    {
        return min(abs(height[0] - height[2]), abs(height[1] - height[2]) + abs(height[1] - height[0]));
    }
    if (n == 1)
    {
        return abs(height[1] - height[0]);
    }
    if (dp[n - 1] != -1)
        return dp[n - 1];
    dp[n - 1] = min(minEnergy(height, n - 1, dp) + abs(height[n] - height[n - 1]), minEnergy(height, n - 2, dp) + abs(height[n] - height[n - 2]));
    return dp[n - 1];
}

// using tabulation
int minEnergyTabulation(int height[], int n, int dp[])
{
    dp[1] = abs(height[1] - height[0]);
    dp[2] = min(abs(height[0] - height[2]), abs(height[1] - height[2]) + abs(height[1] - height[0]));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));
    }
    return dp[n];
}

// space optimization
int minEnergyOptimization(int height[], int n)
{
    // energy required to reach first two steps
    int prevstep = abs(height[1] - height[0]);
    int prev2step = min(abs(height[0] - height[2]), abs(height[1] - height[2]) + abs(height[1] - height[0]));

    for (int i = 3; i <= n; i++)
    {
        int curr = min(prevstep + abs(height[i] - height[i - 1]), prev2step + abs(height[i] - height[i - 2]));
        prev2step = prevstep;
        prevstep = curr;
    }
    return prevstep;
}

int main()
{
    int height[4] = {10, 20, 30, 10};
    int dp[4];
    memset(dp, -1, sizeof(dp));
    cout << minEnergyTabulation(height, 3, dp) << endl;
    cout << minEnergy(height, 3, dp) << endl;
    cout << minEnergyOptimization(height, 3);
    cout << endl;
    return 0;
}
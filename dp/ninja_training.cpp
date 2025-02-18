#include <bits/stdc++.h>
using namespace std;

// roadmap for to solve dp

// brute-force recursion -> Memoization -> Tabulation -> spaceOptimization

int solve(vector<vector<int>> &points, int curr, int ind, int dp[][3])
{ // solving using memoization
    if (curr >= points.size())
        return 0;
    if (dp[curr][ind] != -1)
        return dp[curr][ind];
    int maxv = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != ind)
        {
            maxv = max(maxv, points[curr][i] + solve(points, curr + 1, i, dp));
        }
    }
    return dp[curr][ind] = maxv;
}

// int ninjaTraining(vector<vector<int>>& points){

// }
int tabulation(vector<vector<int>> &points)
{
    // solving using tabulation methon this leads to reduce in space complexity
    // here we will be reducing the stack space of recursion
    int n = points.size();
    int dp[n][3];
    dp[n - 1][0] = max(dp[n - 1][1], dp[n - 1][2]);
    dp[n - 1][1] = max(dp[n - 1][0], dp[n - 1][2]);
    dp[n - 1][2] = max(dp[n - 1][0], dp[n - 1][1]);

    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                    dp[i][j] = max(dp[i][j], points[i][k] + dp[i + 1][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, points[0][i] + dp[1][i]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    // int dp[points.size()][3];
    // memset(dp, -1, sizeof(dp));
    // int maxv = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     maxv = max(maxv, points[0][i] + solve(points, 1, i, dp));
    // }
    // cout << maxv;
    cout << tabulation(points);

    cout << endl;
    return 0;
}
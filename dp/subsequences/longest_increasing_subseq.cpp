#include <bits/stdc++.h>
using namespace std;

int memoize(vector<int> &nums, int ind, int prev, map<int, map<int, int>> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    int notake = memoize(nums, ind - 1, prev, dp);
    if (nums[ind] < prev)
    {
        int take = 1 + memoize(nums, ind - 1, nums[ind], dp);
        dp[ind][prev] = max(notake, take);
        return max(notake, take);
    }
    dp[ind][prev] = notake;
    return notake;
}

int lengthOfLIS(vector<int> &nums)
{
    int s = nums.size();
    map<int, map<int, int>> dp;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            dp[i][nums[j]] = -1;
        }
    }
    int k = memoize(nums, s - 1, INT_MAX, dp);
    cout << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << dp[i][nums[j]];
        }
        cout << endl;
    }
    cout << endl;
    return k;
}

int main()
{
    cout << endl;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);
    cout << endl;
    return 0;
}
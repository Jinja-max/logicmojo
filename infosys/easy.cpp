#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> arr, vector<vector<int>> q)
{
    long long mod = 1000000007;
    long long ans = 0;
    vector<bool> vis(arr.size(), false);
    int cnt = 0;
    for (int i = q.size() - 1; i >= 0; i--)
    {
        int start = q[i][0], end = q[i][1], x = q[i][2], y = q[i][3];
        for (int j = start; j <= end; j++)
        {
            if (!vis[j])
            {
                ans = (ans + x + (j - start) * y) % mod;
                vis[j] = true;
                cnt++;
                if (cnt == arr.size())
                    return ans;
            }
        }
    }
    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
            ans = (ans + arr[i]) % mod;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> queries[i][j];
        }
    }

    cout << solve(arr, queries) << endl;

    cout << endl;
    return 0;
}
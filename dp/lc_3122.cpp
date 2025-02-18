#include <bits/stdc++.h>
using namespace std;

void minimumOperations(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<unordered_map<int, int>> hash;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> mp;
        for (int j = 0; j < m; j++)
        {
            mp[grid[j][i]] = m - (++mp[grid[i][j]]);
        }
        hash.push_back(mp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "--------- " << i + 1 << "------------" << endl;
        for (auto it : hash[i])
        {
            cout << it.first << "->" << it.second << endl;
        }
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 2}, {1, 0, 2}};
    minimumOperations(grid);
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> arr = {1, 2, 1, 3, 2};
    unordered_map<int, pair<int, int>> map;
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]].first == 0)
            map[arr[i]].first = i;
        else
            map[arr[i]].second = i;
    }
    for (auto it : map)
    {
        cout << it.first << "->" << it.second.first << "," << it.second.second << endl;
    }
    cout << endl;
    return 0;
}
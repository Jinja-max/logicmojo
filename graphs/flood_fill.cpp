#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    if (image[sr][sc] == color)
        return image;
    int m = image.size();
    int n = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dir)
        {
            int i = x + dx;
            int j = y + dy;
            if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == image[sr][sc])
            {
                image[i][j] = color;
                q.push({i, j});
            }
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    vector<vector<int>> res = floodFill(image, sr, sc, color);
    for (auto i : res)
    {
        cout << endl;
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// detecting cycle is crucial here

bool dfsCycleDetect(int n, vector<int> adj[], int vis[])
{
    if (vis[n])
        return true;
    vis[n] = 1;
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (vis[adj[n][i] == 0])
        {
            bool ans = dfsCycleDetect(adj[n][i], adj, vis);
            if (ans)
                return true;
        }
    }
    vis[n] = -1;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> adj[numCourses];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    int vis[numCourses];
    for (int i = 0; i < numCourses; i++)
        vis[i] = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (vis[i] == 0)
        {
            bool ans = dfsCycleDetect(i, adj, vis);
            if (ans)
                return ans;
        }
    }
    return false;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << endl;
    return 0;
}
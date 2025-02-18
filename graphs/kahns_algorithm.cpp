// kahns algorithm for topological sort
// uses indegree array and bfs type traversal but not exact bfs
// must return the topological sort of given DAG

#include <bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgo(int n, vector<int> adj[])
{
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }
    cout << "initial indegree array" << endl;
    for (auto i : indegree)
        cout << i << " ";
    cout << endl;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (int i = 0; i < adj[front].size(); i++)
        {
            if (indegree[adj[front][i]] > 0)
            {
                indegree[adj[front][i]]--;
                if (indegree[adj[front][i]] == 0)
                    q.push(adj[front][i]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {2, 0}, {1, 0}};
    vector<int> ans = kahnsAlgo(6, adj);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
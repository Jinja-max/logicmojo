#include <bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void solve(vector<int> &A, vector<int> temp, int &diff, int i, int &max)
{
    int l = A.size();
    int s = temp.size();
    if (i == l)
    {
        if (s > max)
            max = s;
        return;
    }
    if (A[i] > temp[s - 1] && (A[i] - temp[s - 1]) == diff)
    {
        temp.push_back(A[i]);
        if (s > max)
            max = s;
        solve(A, temp, diff, i + 1, max);
    }
    solve(A, temp, diff, i + 1, max);
}

int solution(vector<int> &A)
{
    // Implement your solution here
    int l = A.size();
    if (l == 1)
        return 1;
    if (l == 2)
        return 2;
    int max = 2;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {

            if ((j != i) && A[j] >= A[i])
            {
                vector<int> temp;
                temp.push_back(A[i]);
                temp.push_back(A[j]);
                int diff = temp[1] - temp[0];
                solve(A, temp, diff, 0, max);
            }
        }
    }
    return max;
}

int main()
{
    vector<int> A = {4, 3, 5, 1, 4, 4};
    int max;
    max = solution(A);
    cout << max << endl;
    cout << endl;
    return 0;
}
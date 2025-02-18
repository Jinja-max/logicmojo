#include <bits/stdc++.h>
using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void solve(vector<int> &A, int left, int right, int &sum, int &move, int temp)
{
    if (left >= right)
    {
        if (temp > move)
            move = temp;
        return;
    }
    if (A[left] + A[left + 1] == sum)
    {
        if (temp > move)
            move = temp;
        solve(A, left + 2, right, sum, move, temp + 1);
    }
    if (A[right] + A[right - 1] == sum)
    {

        if (temp > move)
            move = temp;
        solve(A, left, right - 2, sum, move, temp + 1);
    }
    if (A[left] + A[right] == sum)
    {

        if (temp > move)
            move = temp;
        solve(A, left + 1, right - 1, sum, move, temp + 1);
    }
    if (temp > move)
        move = temp;
    return;
}

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    if (N < 2)
        return 0;
    int left = 0;
    int right = N - 1;
    int move = 0;
    int leftsum = A[left] + A[left + 1];
    int rightsum = A[right] + A[right - 1];
    int leftrightsum = A[left] + A[right];
    solve(A, left + 2, right, leftsum, move, 1);
    solve(A, left, right - 2, rightsum, move, 1);
    solve(A, left + 1, right - 1, leftrightsum, move, 1);
    return move;
}

int main()
{
    vector<int> A = {1, 9, 1, 1, 1, 1, 1, 1, 8, 1};
    int move;
    move = solution(A);
    cout << move << endl;
    cout << endl;
    return 0;
}
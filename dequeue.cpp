#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> q;
    // q.push(3);
    // q.push(4);
    // cout << q.top() << endl;
    // q.pop();
    // cout << q.top();
    deque<int> dq;
    dq.push_back(5);
    dq.push_back(10);
    dq.push_front(dq.back());
    dq.pop_back();
    while (!dq.empty())
        dq.pop_back();
    cout << endl;
    cout << dq.size() << endl;
    cout << dq.back() << endl;
    cout << endl;
    return 0;
}
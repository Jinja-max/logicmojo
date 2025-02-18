// unique + not sorted

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> nums;
    nums.insert(1);
    nums.insert(1);
    for (auto it : nums)
        cout << it << endl;

    cout << endl;
    return 0;
}
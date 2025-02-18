#include <bits/stdc++.h>
using namespace std;

int main()
{ // if a new index is added to unordered map the correspoding value of index is 0 by default
    unordered_map<char, char> dict;
    unordered_map<char, int> hash;
    //     hash['a'];
    //     if(dict.count('a')) cout<<"a key is present";
    //     else cout<<"a key is not present";
    //     cout<<hash['a'];
    //     cout<<endl;
    //     return 0;
    // unordered_map<int, vector<int>> mp;
    // mp[2].push_back(4);
    // mp[2].push_back(6);
    // cout << endl;
    // for (auto it : mp[2])
    //     cout << it << " ";
    // cout << endl;
    // mp[2].pop_back();
    // mp[2].pop_back();
    // cout << endl;
    // for (auto it : mp[2])
    //     cout << it << " ";
    // cout << endl;
    // unordered_map<int, bool> visited;
    // visited[1].push_back(false)
    // cout << visited[1] << endl;

    unordered_map<int, int *> mp;
    cout << mp[2] << endl;
    cout << endl;
    return 0;
}
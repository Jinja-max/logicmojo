#include<bits/stdc++.h>
using namespace std;



int main()
{   //if a new index is added to unordered map the correspoding value of index is 0 by default
    unordered_map<char,char> dict;
    unordered_map<char,int> hash;
    hash['a'];
    if(dict.count('a')) cout<<"a key is present";
    else cout<<"a key is not present";
    cout<<hash['a'];
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;



int main()
{
    map<int,char> map1={{1,'a'},{2,'b'},{3,'c'}};
    map<int,int> empty_map;
    map1[4]='d';
   map1.insert({5,'e'});

   for(auto i:map1){
    cout<<i.second<<" ";
   }
    if(empty_map.empty()) cout<<"map is empty";
    else cout<<"map not empty";

    cout<<endl;
    return 0;
}
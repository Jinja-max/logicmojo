#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v1,vector<int> &v2){
    auto j=0;
    auto i=0;
    while (i<v2.size()){
        if(v2[i]<=v1[j]){
            v1.insert(v1.begin()+j,v2[i]);
            i++;    
            }
        else{
            if(j==v1.size()-1){
                v1.push_back(v2[i]);
                i++;
            }
            else
                j++;
        }
    }
    
}

int main()
{
    vector<int> v1={5,7,11,23,43,54,63,75};
    vector<int> v2={6,23,31,44,56,67};
    merge(v1,v2);
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
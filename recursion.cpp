#include<bits/stdc++.h>
using namespace std;

void printname(int count){
    if(count==0) return;
    else{
    cout<<count<<" name "<<endl;
    count--;
    return printname(count);
    }
}

int main()
{
    printname(5);
    cout<<endl;
    return 0;
}
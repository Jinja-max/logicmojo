#include<bits/stdc++.h>
using namespace std;

int fibonacci(int num){
    if(num==1) return 0;
    else if(num==2) return 1;
    else {
        return fibonacci(num-1)+fibonacci(num-2);
    }
}


int main()
{
    for(int i=1;i<=10;i++){
        cout<<fibonacci(i)<<" ";
    }

    cout<<endl;
    return 0;
}
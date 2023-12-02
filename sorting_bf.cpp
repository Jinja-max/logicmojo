#include<bits/stdc++.h>
using namespace std;
void swap(int& a,int& b){
    if(a==b)
        return;
    a=a+b;
    b=a-b;
    a=a-b;
}

void bruteForce_sort(int arr[],int size){
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i+1;j<size;j++)
            if(arr[j]<arr[min])
                min=j;
        swap(arr[i],arr[min]);
    }

}
int main()
{   int arr[5]={65,43,33,54,33};
    bruteForce_sort(arr,5);
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
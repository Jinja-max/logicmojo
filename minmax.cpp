#include<bits/stdc++.h>
using namespace std;

//int min,max,min1,max1;

void minmax(int arr[],int i,int j,int &min,int &max){
    if(i==j){
        min=arr[i];
        max=arr[i];
        }
    else if(i==j-1){
        if(arr[i]>arr[j]){
            min=arr[j];
            max=arr[i];
        }
        else {
            min=arr[i];
            max=arr[j];
        }
    }
    else{
        int mid=(i+j)/2;
        minmax(arr,i,mid,min,max);
        int min1=500,max1=0;
        minmax(arr,mid+1,j,min1,max1);
        if(min1<min) min=min1;
        if(max1>max)    max=max1;
    }
}


int main()
{
    int arr[13]={43,23,2,23,24,32,65,43,75,32,23,246,96};
    int min,max;
    minmax(arr,0,12,min,max);
    cout<<min<<endl<<max;
    cout<<endl;
    return 0;
}
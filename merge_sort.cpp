#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int k=low,i=low,j=mid+1;
    int duplicate[high];
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j])
            duplicate[k++]=arr[i++];
        else
            duplicate[k++]=arr[j++];
    }
    while (i<=mid){
        duplicate[k++]=arr[i++];
    }      
    while (j<=high)
    {
        duplicate[k++]=arr[j++];
    }
    for(auto i=low;i<=high;i++){
        arr[i]=duplicate[i];
    }
    
}
void mergeSort(int arr[],int low,int high){
    if(low==high)
        return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int a[10]={32,11,23,21,43,22,21,54,33,15};
    mergeSort(a,0,9);
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int key,int low,int high){
    if(low>high)    
        return -1;
    else{
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if (arr[mid]>key)
            return binarysearch(arr,key,low,mid-1);
        else
            return binarysearch(arr,key,mid+1,high);
    }
}

int main()
{   int arr[7]={12,23,34,45,56,67,78};
    cout<<binarysearch(arr,34,0,6);
    cout<<endl;
    return 0;
}
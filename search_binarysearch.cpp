
#include<bits/stdc++.h>
using namespace std;
/*We rotate an ascending order sorted array at some point unknown to user. So for instance
 3 4 5 6 7 might become 5 6 7 3 4. Modify binary search algorithm to find an element in the rotated 
 array in O(log n) time and O(1) Space complexity*/

int binarysearch(int arr[],int low,int high,int key){
    int mid=(low+high)/2;
    if(arr[mid]==key) return mid;
    if (arr[mid]>arr[low]){
        if(key<arr[mid] && key>arr[low])
            return binarysearch(arr,low,mid-1,key);
        else
            return binarysearch(arr,mid+1,high,key);
    }
    else
        if(key>arr[mid] && key< high)
            return binarysearch(arr,mid+1,high,key);
        else
            return binarysearch(arr,low,mid-1,key);

}

int main()
{
    int arr[10]={23,23,27,29,13,16,17,19,21,22};
    cout<<binarysearch(arr,0,10,16);
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high && k <= high - low)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid && k <= high - low)
        temp[k++] = arr[i++];
    while (j <= high && k <= high - low)
        temp[k++] = arr[j++];

    for (int idx = low; idx <= high; idx++)
    {
        arr[idx] = temp[idx - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    if (low + 1 == high)
    {
        if (arr[low] > arr[high])
        {
            swap(arr, low, high);
        }
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {54, 3, 33, 22, 2, 23};
    mergeSort(arr, 3, 5);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    cout << endl;
    return 0;
}
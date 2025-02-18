#include <bits/stdc++.h>
using namespace std;
// implementing sorting using merge sort
// a vector has other vectors with 3 elements,
// criteria to sort - based on first elemtent > based on second element > third element
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void merge(vector<vector<int>> &arr, int low, int mid, int high)
{
    vector<vector<int>> ans;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i][0] > arr[j][0])
        {
            ans.push_back(arr[j]);
            j++;
        }
        else if (arr[i][0] == arr[j][0])
        {
            if (arr[i][1] > arr[j][1])
            {
                ans.push_back(arr[j]);
                j++;
            }
            else if (arr[i][1] == arr[j][1])
            {
                if (arr[i][2] > arr[j][2])
                {
                    ans.push_back(arr[j]);
                    j++;
                }
                else
                {
                    ans.push_back(arr[i]);
                    i++;
                }
            }
            else
            {
                ans.push_back(arr[i]);
                i++;
            }
        }
        else
        {
            ans.push_back(arr[i]);
            i++;
        }
    }
    while (i++ <= mid)
        ans.push_back(arr[i]);
    while (j++ <= high)
        ans.push_back(arr[j]);
    for (int k = low; k <= high; k++)
    {
        for (int p = 0; p < 3; p++)
        {
            arr[k][p] = ans[k - low][p];
        }
    }
}

void mergeSort(vector<vector<int>> &arr, int low, int high)
{
    if (low >= high)
        return;
    if (low + 1 == high)
    {
        if (arr[low][0] > arr[high][0])
        {
            for (int i = 0; i < 3; i++)
                swap(arr[low][i], arr[high][i]);
        }
        if (arr[low][0] == arr[high][0])
        {
            if (arr[low][1] > arr[high][1])
            {
                for (int i = 0; i < 2; i++)
                    swap(arr[low][i], arr[high][i]);
            }
            if (arr[low][1] == arr[high][1])
            {
                if (arr[low][2] > arr[high][2])
                    swap(arr[low][2], arr[high][2]);
            }
        }
    }
    int mid = (low + high) / 2;
    cout << endl
         << low << mid << high << endl;
    mergeSort(arr, low, mid);
    for (int i = low; i <= mid; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    mergeSort(arr, mid + 1, high);
    for (int i = mid + 1; i <= high; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    merge(arr, low, mid, high);
    for (int i = low; i <= high; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr = {{4, 2, 4}, {1, 2, 3}, {4, 1, 4}, {1, 1, 2}, {1, 1, 3}};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    // cout << a << " " << b << endl;
    cout << endl;
    return 0;
}
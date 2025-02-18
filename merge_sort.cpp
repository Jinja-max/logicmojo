#include <bits/stdc++.h>
using namespace std;
// below is modified merge sort to solve the n meetings in a room problem using greedy method
// void merge(int arr[], int dependentArr[], int low, int mid, int high)
// {
//     int k = low, i = low, j = mid + 1;
//     int duplicate[high];
//     int dependentDuplicate[high];
//     while (i <= mid && j <= high)
//     {
//         if (arr[i] < arr[j])
//         {
//             dependentDuplicate[k] = dependentArr[i];
//             duplicate[k++] = arr[i++];
//         }
//         else if (arr[i] == arr[j])
//         {
//             if (dependentArr[i] >= dependentArr[j])
//             {
//                 dependentDuplicate[k] = dependentArr[i];
//                 duplicate[k++] = arr[i++];
//             }
//             else
//             {
//                 dependentDuplicate[k] = dependentArr[j];
//                 duplicate[k++] = arr[j++];
//             }
//         }
//         else
//         {
//             dependentDuplicate[k] = dependentArr[j];
//             duplicate[k++] = arr[j++];
//         }
//     }
//     while (i <= mid)
//     {
//         dependentDuplicate[k] = dependentArr[i];
//         duplicate[k++] = arr[i++];
//     }
//     while (j <= high)
//     {
//         dependentDuplicate[k] = dependentArr[j];
//         duplicate[k++] = arr[j++];
//     }
//     for (auto i = low; i <= high; i++)
//     {
//         dependentArr[i] = dependentDuplicate[i];
//         arr[i] = duplicate[i];
//     }
// }
// void mergeSort(int arr[], int dependentArr[], int low, int high)
// {
//     if (low == high)
//         return;
//     int mid = (low + high) / 2;
//     mergeSort(arr, dependentArr, low, mid);
//     mergeSort(arr, dependentArr, mid + 1, high);
//     merge(arr, dependentArr, low, mid, high);
// }

// merge sort on intervals
void mergeIntervals(vector<vector<int>> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    vector<vector<int>> temp;
    while (i <= mid && j <= high)
    {
        if (arr[i][0] < arr[j][0])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i <= high - low; i++)
        arr[low + i] = temp[i];
}
void msortIntervals(vector<vector<int>> &arr, int low, int high)
{
    if (low >= high)
        return;
    if (low + 1 == high && arr[low][0] > arr[high][0])
    {
        auto temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
        return;
    }
    if (low + 1 == high && arr[low][0] == arr[high][0])
    {
        if (arr[low][1] > arr[high][1])
        {
            auto temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
            return;
        }
    }
    int mid = (low + high) / 2;
    msortIntervals(arr, low, mid);
    msortIntervals(arr, mid + 1, high);
    mergeIntervals(arr, low, mid, high);
}
// merge sort on intervals completed

int main()
{
    // int a[4] = {30, 20, 25, 25};
    // int b[4] = {20, 10, 12, 11};
    // mergeSort(a, b, 0, 3);
    // for (auto i : a)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : b)
    //     cout << i << " ";
    cout << endl
         << endl;
    vector<vector<int>> points = {{1, 2}, {4, 5}, {1, 5}};
    msortIntervals(points, 0, points.size() - 1);
    cout << "[ ";
    for (auto i : points)
    {
        cout << "[" << i[0] << "," << i[1] << "]";
    }
    cout << " ]" << endl;
    cout << endl;
    return 0;
}
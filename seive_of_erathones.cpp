#include <bits/stdc++.h>
using namespace std;

void seive(bool arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = true;
    arr[0] = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            int prime = i + 1;
            for (int j = prime + prime; j <= n; j = j + prime)
                arr[j - 1] = false;
        }
    }
}

int main()
{
    cout << "enter the number to know all prime numbers less than it : ";
    int n;
    cin >> n;
    bool arr[n];
    seive(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
            cout << " " << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
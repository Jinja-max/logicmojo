#include <bits/stdc++.h>
using namespace std;
// this is min heap
void percolate_up(vector<int> &heap, int x)
{
    heap.push_back(x);
    int i = heap.size() - 1;

    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        int temp = heap[i];
        heap[i]=heap[(i-1)/2];
        heap[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}


int main()
{
    vector<int> heap;
    cout<<"vscode working"<<endl;
    cout << endl;
    return 0;
}
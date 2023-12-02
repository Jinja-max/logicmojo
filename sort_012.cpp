#include <iostream>

void swap(int& a, int& b) {
    if (a != b) {
        int t = a;
        a = b;
        b = t;
    }
}

void sort012(int arr[], int size) {
    int low = 0;       // Index for 0s
    int high = size - 1; // Index for 2s
    int i = 0;

    while (i <= high) {
        if (arr[i] == 0) {
            swap(arr[i], arr[low]);
            i++;
            low++;
        } else if (arr[i] == 1) {
            i++;
        } else {  // arr[i] == 2
            swap(arr[i], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[6] = {0, 1, 2, 2, 0, 1};
    sort012(arr, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}

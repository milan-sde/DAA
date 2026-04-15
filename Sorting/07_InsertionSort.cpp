#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // shift elements
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 3};
    insertionSort(arr, arr.size());

    for (auto x : arr)
        cout << x << " ";

    cout<<endl;
    return 0;
}
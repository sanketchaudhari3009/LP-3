#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int p, int r, int &counter) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        counter++;  
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int *arr, int p, int r, int &counter) {
    if (p < r) {
        int q = partition(arr, p, r, counter);
        quickSort(arr, p, q - 1, counter);
        quickSort(arr, q + 1, r, counter);
    }
}

int randomPartition(int *arr, int p, int r, int &counter) {
    int x = arr[r];
    int i = rand() % (r - p + 1) + p;
    swap(arr[i], arr[r]);
    counter++;  
    return partition(arr, p, r, counter);
}

void randomizedQuickSort(int *arr, int p, int r, int &counter) {
    if (p < r) {
        int q = randomPartition(arr, p, r, counter);
        randomizedQuickSort(arr, p, q - 1, counter);
        randomizedQuickSort(arr, q + 1, r, counter);
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int A[n], B[n];
    srand(time(0));

    cout << "Enter " << n << " integers for the array:" << endl;
    for (int i = 0; i < n; ++i) {
        while (!(cin >> A[i])) {
            cout << "Invalid input. Please enter integers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        B[i] = A[i]; 
    }

    int counter_quick = 0;
    int counter_randomized = 0;

    quickSort(A, 0, n - 1, counter_quick);
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << '\n';
    cout << "Number of steps for Quick Sort: " << counter_quick << endl;
    
    randomizedQuickSort(B, 0, n - 1, counter_randomized);
    cout << "Sorted array using Randomized Quick Sort: ";
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << '\n';
    cout << "Number of steps for Randomized Quick Sort: " << counter_randomized << endl;

    return 0;
}

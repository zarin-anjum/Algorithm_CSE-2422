#include<iostream>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int smallIndex = start - 1;

    for(int curr = start; curr < end; curr++){
        if(arr[curr] <= pivot){
            smallIndex++;
            swap(arr[smallIndex], arr[curr]);
        }
    }
    swap(arr[smallIndex + 1], arr[end]);
    return smallIndex + 1;
}

void quickSort(int arr[], int start, int end){
    if(start < end){
        int pIndex = partition(arr, start, end);

        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

int main(){
    int n;
    cout << "Enter the number of elements to sort: ";
    cin >> n;

    int arr[n];
    cout << "\nEnter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

void countingSort(int arr[], int n){
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement)
            maxElement = arr[i];
    }

    int* count = new int[maxElement + 1]{0};

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxElement; i++){
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    countingSort(arr, n);

    cout << "Sorted array:   ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}


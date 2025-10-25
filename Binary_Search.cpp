#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);
    cout << "Sorted elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int left = 0, right = n - 1;
    int position = -1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            position = mid;
            break;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(position != -1){
        cout << "Element found at position: " << position + 1 << endl;
    }
    else{
        cout << "Element not found in the list" << endl;
    }

    return 0;
}

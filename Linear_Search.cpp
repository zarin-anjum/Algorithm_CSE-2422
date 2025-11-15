#include <iostream>
using namespace std;

int main(){
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Please enter " << n << " numbers: ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter the number required to find: ";
    cin >> target;

    bool isFound = false;
    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            cout << "Number found at position " << i + 1 << endl;
            isFound = true;
            break;
        }
    }

    if (!isFound){
        cout << "Number not present in the list." << endl;
    }

    return 0;
}

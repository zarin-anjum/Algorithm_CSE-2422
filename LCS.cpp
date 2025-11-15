#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char x[100], y[100];
    cout << "Enter the first string: ";
    cin >> x;
    cout << "Enter the second string: ";
    cin >> y;

    int m = strlen(x);
    int n = strlen(y);

    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(x[i - 1] == y[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else{
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    cout << "Length of LCS: " << L[m][n] << endl;

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS: " << lcs << endl;

    return 0;
}

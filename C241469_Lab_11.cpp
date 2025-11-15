#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int finish;
};

int activitySelection(int start[], int finish[], int n) {
    Activity act[1000];

    for (int i = 0; i < n; i++) {
        act[i].start = start[i];
        act[i].finish = finish[i];
    }

    sort(act, act + n, [](Activity a, Activity b) {
        return a.finish < b.finish;
    });

    int count = 1;
    int lastFinish = act[0].finish;

    for (int i = 1; i < n; i++) {
        if (act[i].start >= lastFinish) {
            count++;
            lastFinish = act[i].finish;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    int start[1000], finish[1000];

    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    cout << "Enter finish times:\n";
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }

    int result = activitySelection(start, finish, n);
    cout << "Maximum number of activities: " << result;

    return 0;
}

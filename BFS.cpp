#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    int adj[100][100] = {0};

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    bool visited[n+1] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 1; i <= n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return 0;
}


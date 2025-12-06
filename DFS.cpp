#include <iostream>
using namespace std;

void dfs(int node, bool visited[], int adj[][100], int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }
}

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
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    bool visited[100] = {false};

    cout << "DFS traversal: ";
    dfs(start, visited, adj, n);

    return 0;
}

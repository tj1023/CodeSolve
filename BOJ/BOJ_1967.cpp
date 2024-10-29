#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> bfs(int n, vector<vector<pair<int, int>>> adj) {
    pair<int, int> distant;
    queue<pair<int, int>> q;
    bool visited[adj.size()] = { 0 };
    q.emplace(n, 0);
    visited[n] = true;

    while (!q.empty()) {
        int curN = q.front().first;
        int curD = q.front().second;
        if (distant.second < curD) distant = { curN, curD };
        q.pop();

        for (int i = 0; i < adj[curN].size(); i++) {
            int nextN = adj[curN][i].first;
            int nextD = curD + adj[curN][i].second;
            if (!visited[nextN]) {
                q.emplace(nextN, nextD);
                visited[nextN] = true;
            }
        }
    }
    return distant;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, v1, v2, w;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2 >> w;
        adj[v1].emplace_back(v2, w);
        adj[v2].emplace_back(v1, w);
    }

    pair<int, int> node1 = bfs(1, adj);
    pair<int, int> node2 = bfs(node1.first, adj);
    cout << node2.second;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int INF = INT_MAX;

vector<int> dijkstra(int start, const unordered_map<int, vector<pii>>& graph, int n) {
    vector<int> distances(n + 1, INF);
    distances[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distances[current_node])
            continue;

        for (const auto& neighbor : graph.at(current_node)) {
            int next_node = neighbor.second;
            int new_distance = current_distance + neighbor.first;

            if (distances[next_node] > new_distance) {
                distances[next_node] = new_distance;
                pq.push({ new_distance, next_node });
            }
        }
    }

    return distances;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, x;
    unordered_map<int, vector<pii>> graph1;
    unordered_map<int, vector<pii>> graph2;
    vector<int> dist1;
    vector<int> dist2;

    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        graph1[s].emplace_back(t, e);
        graph2[e].emplace_back(t, s);
    }

    dist1 = dijkstra(x, graph1, n);
    dist2 = dijkstra(x, graph2, n);
    for (int i = 0; i <= n; i++) {
        if (dist1[i] == INF || dist2[i] == INF) dist1[i] = 0;
        else dist1[i] += dist2[i];
    }

    cout << *max_element(dist1.begin(), dist1.end());

    return 0;
}
// 다익스트라

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

int dijkstra(int s, int e, int n, graph adj) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	vector<int> dist(n + 1, 200000001);
	q.emplace(0, s);
	dist[s] = 0;

	while (!q.empty()) {
		int curd = q.top().first;
		int curv = q.top().second;
		q.pop();
		if (curd > dist[curv]) continue;
		if (curv == e) return curd;

		for (auto next : adj[curv]) {
			int nextd = dist[curv] + next.first;
			int nextv = next.second;
			if (nextd < dist[next.second]) {
				q.emplace(nextd, nextv);
				dist[nextv] = nextd;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, e, a, b, c, v1, v2;
	cin >> n >> e;
	graph adj(n + 1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].emplace_back(c, b);
		adj[b].emplace_back(c, a);
	}
	cin >> v1 >> v2;
	int stov1 = dijkstra(1, v1, n, adj);
	int stov2 = dijkstra(1, v2, n, adj);
	int v1tov2 = dijkstra(v1, v2, n, adj);
	int v1toe = dijkstra(v1, n, n, adj);
	int v2toe = dijkstra(v2, n, n, adj);
	if ((v1tov2 == 0) || ((stov1 == 0 || v2toe == 0) && (stov2 == 0 || v1toe == 0))) cout << -1;
	else cout << min(stov1 + v2toe, stov2 + v1toe) + v1tov2;

	return 0;
}
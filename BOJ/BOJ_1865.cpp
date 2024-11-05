#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int s, e, w;
};

bool hasNegativeCycle(int n, vector<Edge>& edges, int start, vector<bool>& visited) {
	vector<int> dist(n + 1, 10000);
	dist[start] = 0;
	visited[start] = true;

	for (int i = 0; i < n - 1; i++)
		for (const auto& edge : edges)
			if (dist[edge.s] != 10000 && dist[edge.s] + edge.w < dist[edge.e]) {
				dist[edge.e] = dist[edge.s] + edge.w;
				visited[edge.e] = true;
			}

	for (const auto& edge : edges)
		if (dist[edge.s] != 10000 && dist[edge.s] + edge.w < dist[edge.e])
			return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc, n, m, w, s, e, t;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n >> m >> w;
		vector<Edge> edges;
		vector<bool> visited(n + 1, false);
		bool hasNegative = false;
		for (int j = 0; j < m; j++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int j = 0; j < w; j++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		for (int j = 1; j <= n; j++) {
			if (!visited[j] && hasNegativeCycle(n, edges, j, visited)) {
				hasNegative = true;
				break;
			}
		}
		if (hasNegative) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
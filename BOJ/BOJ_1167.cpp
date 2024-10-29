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

	int v, n, in, dist;
	cin >> v;
	vector<vector<pair<int, int>>> adj(v + 1);
	for (int i = 0; i < v; i++) {
		cin >> n;
		while (cin >> in && in != -1) {
			cin >> dist;
			adj[n].emplace_back(in, dist);
		}
	}

	pair<int, int> node1 = bfs(1, adj);
	pair<int, int> node2 = bfs(node1.first, adj);
	cout << node2.second;

	return 0;
}
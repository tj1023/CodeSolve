#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, vector<vector<int>> adj) {
	vector<int> parents(n + 1);
	queue<int> q;
	vector<bool> visited(n + 1, false);
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				parents[next] = cur;
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << parents[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(n, adj);

	return 0;
}
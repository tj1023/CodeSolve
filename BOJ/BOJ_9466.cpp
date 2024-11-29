#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int>& graph, vector<bool>& visited, vector<bool>& finished, int& cycleCount) {
	visited[node] = true;
	int next = graph[node];

	if (!visited[next]) {
		dfs(next, graph, visited, finished, cycleCount);
	}
	else if (!finished[next]) { // ΩŒ¿Ã≈¨ πﬂ∞ﬂ
		int cur = next;
		do {
			cycleCount++;
			cur = graph[cur];
		} while (cur != next);
	}
	finished[node] = true;
}

int countCycleNodes(int n, vector<int>& graph) {
	vector<bool> visited(n + 1, false);
	vector<bool> finished(n + 1, false);
	int cycleCount = 0;

	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs(i, graph, visited, finished, cycleCount);

	return cycleCount;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> graph(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> graph[i];
		cout << n - countCycleNodes(n, graph) << '\n';
	}
	return 0;
}
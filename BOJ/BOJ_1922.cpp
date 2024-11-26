#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v, weight;
	bool operator<(const Edge& other) const { return weight < other.weight; }
};

struct UnionFind {
	vector<int> parent;
	UnionFind(int n) : parent(n + 1) {
		for (int i = 1; i <= n; i++) parent[i] = i;
	}
	int find(int x) { return parent[x] = (parent[x] == x ? x : find(parent[x])); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		parent[x] = y;
		return true;
	}
};

int kruskal(int n, vector<Edge>& edges) {
	sort(edges.begin(), edges.end());
	UnionFind uf(n);
	int mstWeight = 0;
	for (const auto& e : edges)
		if (uf.unite(e.u, e.v))
			mstWeight += e.weight;
	return mstWeight;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a != b)
			edges.push_back({ a,b,c });
	}
	cout << kruskal(n, edges);

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num, degree = 0;
	vector<int> edge;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b, count = 0;
	cin >> n >> m;
	vector<Node> nodes(n + 1);
	for (int i = 1; i <= n; i++)
		nodes[i].num = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		nodes[a].edge.push_back(b);
		nodes[b].degree++;
	}

	while (count < n) {
		queue<Node> q;
		for (int i = 1; i <= n; i++) {
			if (nodes[i].degree == 0) {
				nodes[i].degree--;
				q.push(nodes[i]);
				count++;
			}
		}
		while (!q.empty()) {
			Node cur = q.front();
			q.pop();
			cout << cur.num << ' ';
			for (int i = cur.edge.size() - 1; i >= 0; i--) {
				nodes[cur.edge[i]].degree--;
				cur.edge.pop_back();
			}
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int num, degree = 0, max = 0;
	vector<int> edge;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, k, b1, b2, w;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		Node nodes[n + 1000000];	// 문제의 부분 의도상 n + 1로 돼야하지만 outofbounds 뜸
		int d[n];
		for (int j = 0; j < n; j++)
			cin >> d[j];
		for (int j = 0; j < k; j++) {
			cin >> b1 >> b2;
			nodes[b1].num = b1;
			nodes[b1].edge.push_back(b2);
			nodes[b2].degree++;
		}
		cin >> w;

		queue<Node> q;
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= n; k++) {
				if (nodes[k].degree == 0) {
					nodes[k].degree = -1;
					q.push(nodes[k]);	// 원인으로 추정
				}
			}
			while (!q.empty()) {
				Node cur = q.front();
				q.pop();

				if (cur.num == w) break;
				d[cur.num - 1] += cur.max;

				for (int l = 0; l < cur.edge.size(); l++) {
					nodes[cur.edge[l]].degree--;
					if (nodes[cur.edge[l]].max < d[cur.num - 1])
						nodes[cur.edge[l]].max = d[cur.num - 1];
				}
			}
			if (nodes[w].degree == 0) break;
		}
		d[w - 1] += nodes[w].max;
		cout << d[w - 1] << '\n';
	}

	return 0;
}
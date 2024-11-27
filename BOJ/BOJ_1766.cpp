#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct problem {
	int num, degree = 0;
	vector<int> edge;

	bool operator<(const problem& other) const {
		return num > other.num;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	vector<problem> problems(n + 1);
	priority_queue<problem> pq;
	for (int i = 1; i <= n; i++)
		problems[i].num = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		problems[a].edge.push_back(b);
		problems[b].degree++;
	}

	for (int i = 1; i <= n; i++)
		if (problems[i].degree == 0)
			pq.push(problems[i]);

	while (!pq.empty()) {
		problem cur = pq.top();
		pq.pop();

		cout << cur.num << ' ';
		for (int next : cur.edge) {
			problems[next].degree--;
			if (problems[next].degree == 0)
				pq.push(problems[next]);
		}
	}

	return 0;
}
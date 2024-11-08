#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int bfs(int n, int k) {
	deque<pair<int, int>> q;
	vector<bool> visited(100001, false);
	q.emplace_back(n, 0);
	visited[n] = true;

	while (!q.empty()) {
		int curp = q.front().first;
		int curs = q.front().second;
		q.pop_front();
		if (curp == k) return curs;
		if (curp <= 50000 && !visited[curp * 2]) {
			q.emplace_front(curp * 2, curs);
			visited[curp * 2] = true;
		}
		if (0 < curp && !visited[curp - 1]) {
			q.emplace_back(curp - 1, curs + 1);
			visited[curp - 1] = true;
		}
		if (curp < 100000 && !visited[curp + 1]) {
			q.emplace_back(curp + 1, curs + 1);
			visited[curp + 1] = true;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);

	return 0;
}
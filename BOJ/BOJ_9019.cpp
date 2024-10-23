#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

string bfs(int a, int b) {
	int n;
	int d[4];
	queue<pair<int, string>> q;
	bool visited[10000] = { 0 };
	q.emplace(a, "");
	visited[a] = true;

	while (!q.empty()) {
		int curNum = q.front().first;
		string curStr = q.front().second;
		if (curNum == b) return curStr;
		q.pop();

		d[0] = curNum / 1000;
		d[1] = curNum / 100 % 10;
		d[2] = curNum / 10 % 10;
		d[3] = curNum % 10;

		n = curNum * 2 % 10000;
		if (!visited[n]) {
			q.emplace(n, curStr + 'D');
			visited[n] = true;
		}

		n = curNum != 0 ? curNum - 1 : 9999;
		if (!visited[n]) {
			q.emplace(n, curStr + 'S');
			visited[n] = true;
		}

		n = 1000 * d[1] + 100 * d[2] + 10 * d[3] + d[0];
		if (!visited[n]) {
			q.emplace(n, curStr + 'L');
			visited[n] = true;
		}

		n = 1000 * d[3] + 100 * d[0] + 10 * d[1] + d[2];
		if (!visited[n]) {
			q.emplace(n, curStr + 'R');
			visited[n] = true;
		}
	}
	return "";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}

	return 0;
}
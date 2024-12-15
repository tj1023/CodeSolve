#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct point {
	int place, time;
	vector<int> path;
	point(int p, int t, const vector<int>& pt) : place(p), time(t), path(pt) {}
};

point bfs(int n, int k) {
	deque<point> q;
	vector<bool> visited(100001, false);
	q.emplace_back(n, 0, vector<int>{});
	visited[n] = true;

	while (!q.empty()) {
		int curp = q.front().place;
		int curt = q.front().time;
		vector<int> curpath = q.front().path;
		q.pop_front();
		curpath.push_back(curp);
		if (curp == k) return { curp, curt, curpath };
		if (curp <= 50000 && !visited[curp * 2]) {
			q.emplace_front(curp * 2, curt + 1, curpath);
			visited[curp * 2] = true;
		}
		if (0 < curp && !visited[curp - 1]) {
			q.emplace_back(curp - 1, curt + 1, curpath);
			visited[curp - 1] = true;
		}
		if (curp < 100000 && !visited[curp + 1]) {
			q.emplace_back(curp + 1, curt + 1, curpath);
			visited[curp + 1] = true;
		}
	}
	return { 0,0,{0} };
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	if (n >= k) {
		cout << n - k << '\n';
		for (int i = n; i >= k; i--) cout << i << ' ';
		return 0;
	}
	point ans = bfs(n, k);
	cout << ans.time << '\n';
	for (int p : ans.path) cout << p << ' ';

	return 0;
}
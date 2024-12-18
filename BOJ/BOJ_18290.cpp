#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
int maxV = -40000;
vector<vector<int>> grid(10, vector<int>(10));
vector<pair<int, int>> choice;

bool check(int y, int x) {
	for (int i = 0; i < choice.size(); i++)
		if (abs(choice[i].first - y) + abs(choice[i].second - x) == 1) return false;
	return true;
}

void bt(int depth, int sum, int y, int x) {
	if (depth == k) { maxV = max(maxV, sum); return; }
	for (int i = y; i < n; i++) {
		for (int j = (i == y ? x : 0); j < m; j++) {
			if (check(i, j)) {
				choice.push_back({ i, j });
				bt(depth + 1, sum + grid[i][j], i + (j + 1) / m, (j + 1) % m);
				choice.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	bt(0, 0, 0, 0);
	cout << maxV;

	return 0;
}
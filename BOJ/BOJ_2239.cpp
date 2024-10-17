#include <iostream>
#include <cstdlib>
using namespace std;

int grid[9][9];

bool check(int y, int x, int n) {
	int yOffset = y / 3 * 3;
	int xOffset = x / 3 * 3;
	for (int i = 0; i < 9; i++)
		if (grid[y][i] == n || grid[i][x] == n)
			return false;
	for (int i = yOffset; i < yOffset + 3; i++)
		for (int j = xOffset; j < xOffset + 3; j++)
			if (grid[i][j] == n) return false;
	return true;
}

void bt(int y, int x) {
	for (int i = y; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == y && j == 0) j = x;
			if (grid[i][j] != 0) continue;
			for (int k = 1; k <= 10; k++) {
				if (k == 10) return;
				if (check(i, j, k)) {
					grid[i][j] = k;
					bt(i + (j + 1) / 9, (j + 1) % 9);
					grid[i][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << grid[i][j];
		cout << '\n';
	}
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string n;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		for (int j = 0; j < 9; j++)
			grid[i][j] = n[j] - '0';
	}
	bt(0, 0);

	return 0;
}
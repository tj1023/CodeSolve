#include <iostream>
#include <vector>
using namespace std;

int n, blackMax = 0, whiteMax = 0;
vector<vector<int>> board(10, vector<int>(10));
vector<int> blackBishop(10, -1);
vector<int> whiteBishop(9, -1);

bool blackCheck(int y, int x) {
	for (int i = 0; i < y; i++) {
		if (blackBishop[i] == -1) continue;
		if (y - i == x - blackBishop[i]) return false;
	}
	return true;
}

bool whiteCheck(int y, int x) {
	for (int i = 0; i < y; i++) {
		if (whiteBishop[i] == -1) continue;
		if (y - i == x - whiteBishop[i]) return false;
	}
	return true;
}

void black(int d, int count) {
	if (d == n) {
		if (blackMax < count) blackMax = count;
		return;
	}
	bool allBLock = true;
	for (int i = 0; i < d * 2 + 1; i++) {
		if (d * 2 - i >= n) continue; if (i == n) break;
		if (board[d * 2 - i][i] == 1 && blackCheck(d, i)) {
			blackBishop[d] = i;
			black(d + 1, count + 1);
			blackBishop[d] = -1;
			allBLock = false;
		}
		else if ((i == d * 2 || i == n - 1) && allBLock) black(d + 1, count);
	}
}

void white(int d, int count) {
	if (d == n - 1) {
		if (whiteMax < count) whiteMax = count;
		return;
	}
	bool allBLock = true;
	for (int i = 0; i <= d * 2 + 1; i++) {
		if (d * 2 + 1 - i >= n) continue; if (i == n) break;
		if (board[d * 2 + 1 - i][i] == 1 && whiteCheck(d, i)) {
			whiteBishop[d] = i;
			white(d + 1, count + 1);
			whiteBishop[d] = -1;
			allBLock = false;
		}
		else if ((i == d * 2 + 1 || i == n - 1) && allBLock) white(d + 1, count);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	black(0, 0);
	white(0, 0);
	cout << blackMax + whiteMax;

	return 0;
}
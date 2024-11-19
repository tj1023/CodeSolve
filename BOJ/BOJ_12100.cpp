#include <iostream>
#include <vector>
using namespace std;

int N, maxnum = 0;

void game(int n, vector<vector<int>> board, string str) {
	if (n == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (maxnum < board[i][j])
					maxnum = board[i][j];
		return;
	}

	// ก่
	vector<vector<int>> new_board(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = 0;
		int prev = 0;
		for (int j = 0; j < N; j++) {
			if (board[j][i] == 0) {
				if (j == N - 1) new_board[idx][i] = prev;
				continue;
			}
			if (prev == 0) {
				prev = board[j][i];
				if (j == N - 1) new_board[idx][i] = prev;
				continue;
			}
			if (prev == board[j][i]) {
				new_board[idx][i] = prev * 2;
				idx++;
				prev = 0;
			}
			else {
				new_board[idx][i] = prev;
				idx++;
				prev = board[j][i];
				if (j == N - 1) new_board[idx][i] = prev;
			}
		}
	}
	game(n + 1, new_board, str + "ก่");

	// ก้
	new_board.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		int prev = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (board[j][i] == 0) {
				if (j == 0) new_board[idx][i] = prev;
				continue;
			}
			if (prev == 0) {
				prev = board[j][i];
				if (j == 0) new_board[idx][i] = prev;
				continue;
			}
			if (prev == board[j][i]) {
				new_board[idx][i] = prev * 2;
				idx--;
				prev = 0;
			}
			else {
				new_board[idx][i] = prev;
				idx--;
				prev = board[j][i];
				if (j == 0) new_board[idx][i] = prev;
			}
		}
	}
	game(n + 1, new_board, str + "ก้");

	// ก็
	new_board.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = 0;
		int prev = 0;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				if (j == N - 1) new_board[i][idx] = prev;
				continue;
			}
			if (prev == 0) {
				prev = board[i][j];
				if (j == N - 1) new_board[i][idx] = prev;
				continue;
			}
			if (prev == board[i][j]) {
				new_board[i][idx] = prev * 2;
				idx++;
				prev = 0;
			}
			else {
				new_board[i][idx] = prev;
				idx++;
				prev = board[i][j];
				if (j == N - 1) new_board[i][idx] = prev;
			}
		}
	}
	game(n + 1, new_board, str + "ก็");

	// กๆ
	new_board.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		int idx = N - 1;
		int prev = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (board[i][j] == 0) {
				if (j == 0) new_board[i][idx] = prev;
				continue;
			}
			if (prev == 0) {
				prev = board[i][j];
				if (j == 0) new_board[i][idx] = prev;
				continue;
			}
			if (prev == board[i][j]) {
				new_board[i][idx] = prev * 2;
				idx--;
				prev = 0;
			}
			else {
				new_board[i][idx] = prev;
				idx--;
				prev = board[i][j];
				if (j == 0) new_board[i][idx] = prev;
			}
		}
	}
	game(n + 1, new_board, str + "กๆ");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	game(0, board, "");
	cout << maxnum;

	return 0;
}
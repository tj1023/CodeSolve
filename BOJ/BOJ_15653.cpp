#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> point;

int n, m;

struct node {
	int y, x, depth;
};

int bfs(point hole, point red, point blue, vector<vector<char>> board) {
	queue<node> rq;
	queue<node> bq;
	bool visited[10][10][10][10] = {};
	rq.push({ red.first, red.second, 0 });
	bq.push({ blue.first, blue.second, 0 });
	visited[red.first][red.second][blue.first][blue.second] = true;

	while (!rq.empty() && !bq.empty()) {
		node curr = rq.front(); rq.pop();
		node curb = bq.front(); bq.pop();

		// ╩С
		point nextr = { curr.y, curr.x };
		point nextb = { curb.y, curb.x };
		bool canMove = true;
		bool redGoal = false;
		if (curr.y < curb.y) {
			while (nextr.first - 1 >= 0 && board[nextr.first - 1][nextr.second] != '#') {
				nextr.first--;
				if (board[nextr.first][nextr.second] == 'O') {
					redGoal = true;
					nextr = { 0,0 };
					break;
				}
			}
			while (nextb.first - 1 >= 0 && board[nextb.first - 1][nextb.second] != '#' &&
				!(nextr.first == nextb.first - 1 && nextr.second == nextb.second)) {
				nextb.first--;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (redGoal && canMove) return curr.depth + 1;
		}
		else {
			while (nextb.first - 1 >= 0 && board[nextb.first - 1][nextb.second] != '#') {
				nextb.first--;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (canMove) {
				while (nextr.first - 1 >= 0 && board[nextr.first - 1][nextr.second] != '#' &&
					!(nextr.first - 1 == nextb.first && nextr.second == nextb.second)) {
					nextr.first--;
					if (board[nextr.first][nextr.second] == 'O') return curr.depth + 1;
				}
			}
		}
		if (canMove && !visited[nextr.first][nextr.second][nextb.first][nextb.second]) {
			rq.push({ nextr.first, nextr.second, curr.depth + 1 });
			bq.push({ nextb.first, nextb.second, curr.depth + 1 });
			visited[nextr.first][nextr.second][nextb.first][nextb.second] = true;
		}

		// го
		nextr = { curr.y, curr.x };
		nextb = { curb.y, curb.x };
		canMove = true;
		if (curr.y > curb.y) {
			while (nextr.first + 1 < n && board[nextr.first + 1][nextr.second] != '#') {
				nextr.first++;
				if (board[nextr.first][nextr.second] == 'O') {
					redGoal = true;
					nextr = { 0,0 };
					break;
				}
			}
			while (nextb.first + 1 < n && board[nextb.first + 1][nextb.second] != '#' &&
				!(nextr.first == nextb.first + 1 && nextr.second == nextb.second)) {
				nextb.first++;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (redGoal && canMove) return curr.depth + 1;
		}
		else {
			while (nextb.first + 1 < n && board[nextb.first + 1][nextb.second] != '#') {
				nextb.first++;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (canMove) {
				while (nextr.first + 1 < n && board[nextr.first + 1][nextr.second] != '#' &&
					!(nextr.first + 1 == nextb.first && nextr.second == nextb.second)) {
					nextr.first++;
					if (board[nextr.first][nextr.second] == 'O') return curr.depth + 1;
				}
			}
		}
		if (canMove && !visited[nextr.first][nextr.second][nextb.first][nextb.second]) {
			rq.push({ nextr.first, nextr.second, curr.depth + 1 });
			bq.push({ nextb.first, nextb.second, curr.depth + 1 });
			visited[nextr.first][nextr.second][nextb.first][nextb.second] = true;
		}

		// аб
		nextr = { curr.y, curr.x };
		nextb = { curb.y, curb.x };
		canMove = true;
		if (curr.x < curb.x) {
			while (nextr.second - 1 >= 0 && board[nextr.first][nextr.second - 1] != '#') {
				nextr.second--;
				if (board[nextr.first][nextr.second] == 'O') {
					redGoal = true;
					nextr = { 0,0 };
					break;
				}
			}
			while (nextb.second - 1 >= 0 && board[nextb.first][nextb.second - 1] != '#' &&
				!(nextr.first == nextb.first && nextr.second == nextb.second - 1)) {
				nextb.second--;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (redGoal && canMove) return curr.depth + 1;
		}
		else {
			while (nextb.second - 1 >= 0 && board[nextb.first][nextb.second - 1] != '#') {
				nextb.second--;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (canMove) {
				while (nextr.second - 1 >= 0 && board[nextr.first][nextr.second - 1] != '#' &&
					!(nextr.first == nextb.first && nextr.second - 1 == nextb.second)) {
					nextr.second--;
					if (board[nextr.first][nextr.second] == 'O') return curr.depth + 1;
				}
			}
		}
		if (canMove && !visited[nextr.first][nextr.second][nextb.first][nextb.second]) {
			rq.push({ nextr.first, nextr.second, curr.depth + 1 });
			bq.push({ nextb.first, nextb.second, curr.depth + 1 });
			visited[nextr.first][nextr.second][nextb.first][nextb.second] = true;
		}

		// ©Л
		nextr = { curr.y, curr.x };
		nextb = { curb.y, curb.x };
		canMove = true;
		if (curr.x > curb.x) {
			while (nextr.second + 1 < m && board[nextr.first][nextr.second + 1] != '#') {
				nextr.second++;
				if (board[nextr.first][nextr.second] == 'O') {
					redGoal = true;
					nextr = { 0,0 };
					break;
				}
			}
			while (nextb.second + 1 < m && board[nextb.first][nextb.second + 1] != '#' &&
				!(nextr.first == nextb.first && nextr.second == nextb.second + 1)) {
				nextb.second++;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (redGoal && canMove) return curr.depth + 1;
		}
		else {
			while (nextb.second + 1 < m && board[nextb.first][nextb.second + 1] != '#') {
				nextb.second++;
				if (board[nextb.first][nextb.second] == 'O') { canMove = false; break; }
			}
			if (canMove) {
				while (nextr.second + 1 < m && board[nextr.first][nextr.second + 1] != '#' &&
					!(nextr.first == nextb.first && nextr.second + 1 == nextb.second)) {
					nextr.second++;
					if (board[nextr.first][nextr.second] == 'O') return curr.depth + 1;
				}
			}
		}
		if (canMove && !visited[nextr.first][nextr.second][nextb.first][nextb.second]) {
			rq.push({ nextr.first, nextr.second, curr.depth + 1 });
			bq.push({ nextb.first, nextb.second, curr.depth + 1 });
			visited[nextr.first][nextr.second][nextb.first][nextb.second] = true;
		}
	} return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char input;
	point hole, red, blue;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input;
			board[i][j] = input;
			if (input == 'O') hole = { i,j };
			else if (input == 'R') red = { i,j };
			else if (input == 'B') blue = { i,j };
		}
	}
	cout << bfs(hole, red, blue, board);

	return 0;
}
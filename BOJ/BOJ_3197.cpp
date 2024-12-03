#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int bfs(pair<int, int> swan, queue<pair<int, int>> waterQ, vector<vector<bool>> waterVisited, vector<vector<char>> grid) {
    int day = 0;
    queue<pair<int, int>> swanQ;
    queue<pair<int, int>> nextSwanQ;
    queue<pair<int, int>> nextWaterQ;
    vector<vector<bool>> swanVisited(r, vector<bool>(c, false));

    swanQ.push(swan);
    swanVisited[swan.first][swan.second] = true;

    while (!swanQ.empty()) {
        while (!swanQ.empty()) {
            pair<int, int> curSwan = swanQ.front();
            swanQ.pop();

            for (int i = 0; i < 4; i++) {
                int ny = curSwan.first + dir[i][0];
                int nx = curSwan.second + dir[i][1];
                if (0 <= ny && ny < r && 0 <= nx && nx < c && !swanVisited[ny][nx]) {
                    if (grid[ny][nx] == '.') {
                        swanQ.emplace(ny, nx);
                        swanVisited[ny][nx] = true;
                    }
                    else if (grid[ny][nx] == 'X') {
                        nextSwanQ.emplace(ny, nx);
                        swanVisited[ny][nx] = true;
                    }
                    else return day;
                }
            }
        }
        swanQ = nextSwanQ;
        nextSwanQ = queue<pair<int, int>>();

        while (!waterQ.empty()) {
            pair<int, int> curWater = waterQ.front();
            waterQ.pop();

            for (int i = 0; i < 4; i++) {
                int ny = curWater.first + dir[i][0];
                int nx = curWater.second + dir[i][1];
                if (0 <= ny && ny < r && 0 <= nx && nx < c && !waterVisited[ny][nx]) {
                    if (grid[ny][nx] != 'X') {
                        waterQ.emplace(ny, nx);
                        waterVisited[ny][nx] = true;
                    }
                    else {
                        grid[ny][nx] = '.';
                        nextWaterQ.emplace(ny, nx);
                        waterVisited[ny][nx] = true;
                    }
                }
            }
        }
        waterQ = nextWaterQ;
        nextWaterQ = queue<pair<int, int>>();

        day++;
    }

    return day;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pair<int, int> swan;
    queue<pair<int, int>> waterQ;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<bool>> waterVisited(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 'X') {
                waterQ.emplace(i, j);
                waterVisited[i][j] = true;
                if (grid[i][j] == 'L') swan = { i,j };
            }
        }
    }

    cout << bfs(swan, waterQ, waterVisited, grid);

    return 0;
}
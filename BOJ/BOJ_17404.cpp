#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 1000000;
	cin >> n;
	vector<vector<int>> rgb(3, vector<int>(n));
	vector<vector<int>> dp_r(3, vector<int>(n));
	vector<vector<int>> dp_g(3, vector<int>(n));
	vector<vector<int>> dp_b(3, vector<int>(n));

	for (int i = 0; i < n; i++)
		cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
	for (int i = 0; i < 3; i++) {
		dp_r[i][0] = rgb[i][0];
		dp_g[i][0] = rgb[i][0];
		dp_b[i][0] = rgb[i][0];
	}

	dp_r[0][1] = 2000;
	dp_r[1][1] = rgb[1][0] + rgb[0][1];
	dp_r[2][1] = rgb[2][0] + rgb[0][1];

	dp_g[0][1] = rgb[0][0] + rgb[1][1];
	dp_g[1][1] = 2000;
	dp_g[2][1] = rgb[2][0] + rgb[1][1];

	dp_b[0][1] = rgb[0][0] + rgb[2][1];
	dp_b[1][1] = rgb[1][0] + rgb[2][1];
	dp_b[2][1] = 2000;

	for (int i = 0; i < 3; i++) {
		for (int j = 2; j < n; j++) {
			dp_r[i][j] = min(dp_g[i][j - 1], dp_b[i][j - 1]) + rgb[0][j];
			dp_g[i][j] = min(dp_r[i][j - 1], dp_b[i][j - 1]) + rgb[1][j];
			dp_b[i][j] = min(dp_r[i][j - 1], dp_g[i][j - 1]) + rgb[2][j];
		}
	}

	dp_r[0][n - 1] = 1000000;
	dp_g[1][n - 1] = 1000000;
	dp_b[2][n - 1] = 1000000;

	for (int i = 0; i < 3; i++)
		ans = min({ ans, dp_r[i][n - 1], dp_g[i][n - 1], dp_b[i][n - 1] });
	cout << ans;

	return 0;
}
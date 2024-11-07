#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	int maxDist = 100000 * (n - 1) + 1;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, maxDist));
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] >= maxDist) cout << "0 ";
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
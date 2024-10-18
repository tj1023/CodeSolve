#include <iostream>
#include <algorithm>
#define N 1001
using namespace std;

int dp[N][N];
string str1, str2;

void print(int i, int j) {
	if (dp[i][j] == 0)return;
	if (str1[i - 1] == str2[j - 1]) {
		print(i - 1, j - 1);
		cout << str1[i - 1];
	}
	else dp[i - 1][j] > dp[i][j - 1] ? print(i - 1, j) : print(i, j - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str1 >> str2;
	int i, j = 0;
	for (i = 0; str1[i]; ++i)for (j = 0; str2[j]; ++j) {
		if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
		else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

	}
	cout << dp[i][j] << '\n';
	print(i, j);
	return 0;
}
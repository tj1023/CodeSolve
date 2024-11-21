#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	int n = str.size();
	vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
	vector<int> dp(n, 2500);

	for (int i = 0; i < n; i++)
		isPalindrome[i][i] = true;
	for (int i = 0; i < n - 1; i++)
		if (str[i] == str[i + 1])
			isPalindrome[i][i + 1] = true;
	for (int i = 2; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (str[j] == str[i + j] && isPalindrome[j + 1][i + j - 1])
				isPalindrome[j][i + j] = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isPalindrome[j][i]) {
				if (j == 0) { dp[i] = 1; break; }
				if (dp[i] > dp[j - 1] + 1) dp[i] = dp[j - 1] + 1;
			}
		}
	}
	cout << dp[n - 1];

	return 0;
}
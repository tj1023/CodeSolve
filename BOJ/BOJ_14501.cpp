#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> t(15);
vector<int> p(15);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];

	vector<int> dp(15, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (n - i < t[i]) continue;
		dp[i] = p[i];
		vector<int> list;
		for (int j = i + t[i]; j < n; j++)
			if (n - j >= t[j]) list.push_back(dp[j]);
		if (!list.empty())
			dp[i] += *max_element(list.begin(), list.end());
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct nation {
	int num;
	vector<int> medal;
	nation() :medal(3) {}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k, idx;
	cin >> n >> k;
	vector<nation> nations(n);
	for (int i = 0; i < n; i++)
		cin >> nations[i].num >> nations[i].medal[0] >> nations[i].medal[1] >> nations[i].medal[2];

	sort(nations.begin(), nations.end(), [](const nation& n1, const nation& n2) {
		if (n1.medal[0] == n2.medal[0]) {
			if (n1.medal[1] == n2.medal[1])
				return n1.medal[2] > n2.medal[2];
			return n1.medal[1] > n2.medal[1];
		} return n1.medal[0] > n2.medal[0];
		});
	for (int i = 0; i < n; i++) if (nations[i].num == k) idx = i;
	for (int i = idx - 1; i >= 0; i--)
		if (nations[idx].medal[0] == nations[i].medal[0] &&
			nations[idx].medal[1] == nations[i].medal[1] &&
			nations[idx].medal[2] == nations[i].medal[2])
			idx--;
	cout << idx + 1;

	return 0;
}
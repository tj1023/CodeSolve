#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// declaration and initialization
	int n, k, m, v, c, idx = 0;
	long long sum = 0;
	cin >> n >> k;
	vector<pair<int, int>> gems(n);
	vector<int> bags(k);
	priority_queue<int> pq;

	// input, sort by weight
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		gems[i] = { m, v };
	}
	for (int i = 0; i < k; i++) {
		cin >> c;
		bags[i] = c;
	}
	sort(gems.begin(), gems.end());
	sort(bags.begin(), bags.end());

	// find max value gem that can put in bag
	for (int bag : bags) {
		for (int i = idx; i < n; i++) {
			if (gems[i].first <= bag) {
				pq.emplace(gems[i].second);
				if (i == n - 1) idx = n;
			}
			else {
				idx = i;
				break;
			}
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}
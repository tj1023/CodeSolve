#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, ans;
	string str;
	vector<string> v;
	unordered_map<string, int> map;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ans = 1;
		for (int j = 0; j < n; j++) {
			cin >> str >> str;
			if (find(v.begin(), v.end(), str) == v.end())
				v.push_back(str);
			map[str]++;
		}
		for (int j = 0; j < v.size(); j++)
			ans *= map[v[j]] + 1;
		cout << ans - 1 << '\n';
		map.clear();
	}

	return 0;
}
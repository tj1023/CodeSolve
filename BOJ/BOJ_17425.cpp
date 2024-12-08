#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n;
	vector<long long> v(1000001, 0);

	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; i * j <= 1000000; j++)
			v[i * j] += i;
		v[i] += v[i - 1];
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << v[n] << '\n';
	}

	return 0;
}
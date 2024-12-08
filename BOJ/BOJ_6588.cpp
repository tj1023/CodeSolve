#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	const int MAX_N = 1000000;
	vector<bool> isPrime(MAX_N + 1, true);
	vector<int> primeNum;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(MAX_N); ++i) {
		if (isPrime[i]) {
			primeNum.push_back(i);
			for (int j = i * i; j <= MAX_N; j += i)
				isPrime[j] = false;
		}
	}

	int n;
	while (cin >> n && n) {
		for (int num : primeNum) {
			if (isPrime[n - num]) {
				cout << n << " = " << num << " + " << n - num << '\n';
				break;
			}
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, front = 0, sum = 0, count = 0;
	cin >> n;
	vector<bool> isPrime(n + 1, true);
	vector<int> prime;
	queue<int> q;
	isPrime[0] = false; isPrime[1] = false;

	// 에라토스테네스의 체
	for (int i = 2; i * i <= n; i++)
		if (isPrime[i])
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
	for (int i = 2; i <= n; i++)
		if (isPrime[i]) prime.push_back(i);

	// queue를 투포인터로 사용
	for (int i = 0; i < prime.size(); i++) {
		sum += prime[i];
		q.push(prime[i]);
		while (sum > n && !q.empty()) {
			sum -= q.front();
			q.pop();
		}
		if (sum == n) count++;
	}

	cout << count;

	return 0;
}
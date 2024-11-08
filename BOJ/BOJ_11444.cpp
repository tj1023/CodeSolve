#include <iostream>
#include <vector>
using namespace std;

vector<long long> multiply(vector<long long> a, vector<long long> b) {
	vector<long long> result(4);
	result[0] = (a[0] * b[0] + a[1] * b[2]) % 1000000007;
	result[1] = (a[0] * b[1] + a[1] * b[3]) % 1000000007;
	result[2] = (a[2] * b[0] + a[3] * b[2]) % 1000000007;
	result[3] = (a[2] * b[1] + a[3] * b[3]) % 1000000007;
	return result;
}

vector<long long> powMat(vector<long long> mat, long long n) {
	if (n == 1) return mat;
	if (n % 2 == 0) {
		vector<long long> half = powMat(mat, n / 2);
		return multiply(half, half);
	}
	else return multiply(mat, powMat(mat, n - 1));
}

long long fib(long long n) {
	if (n <= 1) return n;
	vector<long long> mat = { 1,1,1,0 };
	vector<long long> result = powMat(mat, n - 1);
	return result[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	cout << fib(n);

	return 0;
}
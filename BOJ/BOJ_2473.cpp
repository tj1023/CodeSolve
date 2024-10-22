#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, mini = 1;
	long long sol[5000];
	long long ans[3];
	long long minminsum = 3000000000;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sol[i];
	sort(sol, sol + n);

	for (int i = 0; i < n; i++) {
		int left = 0, minleft = 0;
		int right = n - 1, minright = n - 1;
		long long sum, minsum = abs(sol[0] + sol[1] + sol[n - 1]);

		while (left < right - 1) {
			if (left == i) left++; if (right == i) right--;
			if (abs(sol[i] + sol[left] + sol[right - 1]) <= abs(sol[i] + sol[left + 1] + sol[right]))
				right--; else left++;
			if (left == i || right == i) continue;
			if (left >= right) break;
			sum = abs(sol[i] + sol[left] + sol[right]);

			if (minsum > sum) {
				if (sum == 0) {
					long long s[3] = { sol[i], sol[left], sol[right] };
					sort(s, s + 3);
					cout << s[0] << ' ' << s[1] << ' ' << s[2];
					return 0;
				}
				mini = i;
				minleft = left;
				minright = right;
				minsum = sum;
			}
		}
		if (minminsum > minsum) {
			minminsum = minsum;
			long long s[3] = { sol[mini], sol[minleft], sol[minright] };
			copy(s, s + 3, ans);
		}
	}
	sort(ans, ans + 3);
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];

	return 0;
}
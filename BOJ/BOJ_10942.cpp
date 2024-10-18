#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, s, e;
    cin >> n;
    int nums[n];
    int palindrome[n + 1][n + 1] = { 0 };
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> m;

    for (int i = 1; i <= n; i++) palindrome[i][i] = 1;
    for (int i = 1; i < n; i++) if (nums[i - 1] == nums[i]) palindrome[i][i + 1] = 1;
    for (int i = 2; i < n; i++) for (int j = 1; j <= n - i; j++)
        if (palindrome[j + 1][i + j - 1] == 1 && nums[j - 1] == nums[i + j - 1])
            palindrome[j][i + j] = 1;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << palindrome[s][e] << '\n';
    }

    return 0;
}
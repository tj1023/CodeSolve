#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x, y;
    int dp[101];
    unordered_map<int, int> ledderIn;
    unordered_map<int, int> ledderOut;
    unordered_map<int, int> snake;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ledderIn.emplace(x, y);
        ledderOut.emplace(y, x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        snake.emplace(x, y);
    }

    for (int i = 2; i <= 7; i++)
        dp[i] = 1;
    for (int i = 8; i <= 100; i++) {
        vector<int> pre;
        for (int j = 6; j > 0; j--)
            if (!ledderIn.count(i - j) && !snake.count(i - j))
                pre.push_back(dp[i - j] + 1);
        if (ledderOut.count(i)) pre.push_back(dp[ledderOut[i]]);
        dp[i] = *min_element(pre.begin(), pre.end());

        if (snake.count(i) && dp[i] < dp[snake[i]]) {
            dp[snake[i]] = dp[i];
            i = snake[i];
        }
    }

    cout << dp[100];

    return 0;
}
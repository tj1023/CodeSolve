#include <iostream>
#include <queue>
using namespace std;

int fruits[10] = { 0 };

bool check() {
    int c = 0;
    for (int i = 1; i <= 9; i++)
        if (fruits[i] > 0) c++;
    return c > 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, fruit, count = 0, max = 1;
    queue<int> skewer;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> fruit;
        fruits[fruit]++;
        skewer.push(fruit);
        count++;
        while (!skewer.empty() && check()) {
            fruits[skewer.front()]--;
            skewer.pop();
            count--;
        }
        if (count > max) max = count;
    }
    cout << max;

    return 0;
}
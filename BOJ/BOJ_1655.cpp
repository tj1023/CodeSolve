#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, num, leftCount = 0, rightCount = 0;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    cin >> n >> num;
    cout << num << '\n';
    left.push(num);
    leftCount++;

    for (int i = 1; i < n; i++) {
        cin >> num;
        if (leftCount <= rightCount) {
            if (num <= right.top()) {
                left.push(num);
                leftCount++;
                cout << left.top() << '\n';
            }
            else {
                cout << right.top() << '\n';
                left.push(right.top());
                right.pop();
                leftCount++;
                right.push(num);
            }
        }
        else {
            if (num >= left.top()) {
                right.push(num);
                rightCount++;
                cout << left.top() << '\n';
            }
            else {
                right.push(left.top());
                left.pop();
                rightCount++;
                left.push(num);
                cout << left.top() << '\n';
            }
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include<cstring>
using namespace std;

vector<int> v[100];
int visited[100];

void dfs(int x) {
    for (int i = 0; i < v[x].size(); i++) {
        if (!visited[v[x][i]]) {
            visited[v[x][i]] = 1;
            dfs(v[x][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, in;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> in;
            if (in) v[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for (int j = 0; j < n; j++)
            cout << visited[j] << " ";
        cout << '\n';
    }

    return 0;
}
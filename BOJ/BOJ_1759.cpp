#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> v;
string pw = "";

bool check(string str) {
	int vowel = 0;
	int consonant = 0;
	for (char c : str) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
		else consonant++;
	}
	if (vowel >= 1 && consonant >= 2) return true;
	return false;
}

void bt(int depth, int idx) {
	if (depth == l) { if (check(pw)) cout << pw << '\n'; return; }
	for (int i = idx; i < c; i++) {
		pw += v[i];
		bt(depth + 1, i + 1);
		pw.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char alp;
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> alp;
		v.push_back(alp);
	}

	sort(v.begin(), v.end());
	bt(0, 0);

	return 0;
}
#include <bits/stdc++.h>

using namespace std;
int n, m;
pair<int, int>s[2];
vector<pair<int, int>> vec(16);
vector<bool>check(16);
bool found;


void getDominos(int conn, int counter) {
	if (found) return;
	if (counter == n) {
		if (conn == s[1].first)
			found = 1;
		return;
	}

	for (int i = 0; i < m; i++) {
		if(check[i]) continue;
		if (vec[i].first == conn) {
			check[i] = 1;
			getDominos(vec[i].second, counter + 1);
			check[i] = 0;
		}
		else if(vec[i].second == conn) {
			check[i] = 1;  
			getDominos(vec[i].first, counter + 1);
			check[i] = 0;

		}
	}
}

int main() {

	while (cin >> n, n != 0) {
		cin >> m;
		cin >> s[0].first >> s[0].second;
		cin >> s[1].first >> s[1].second;

		for (int i = 0; i < m; i++) {
			cin >> vec[i].first >> vec[i].second;
		}		

		getDominos(s[0].second, 0);

		if (found) cout << "YES" << endl;
		else cout << "NO" << endl;

		found = 0;
		check = vector<bool>(16, 0);
	}
	return 0;
}

#include <bits/stdc++.h>
 
using namespace std;

#define F first
#define S second

int N, tCase;
vector<bool>check(20);
vector<bool>prime(40, 1);
vector<vector<int>> ans;
vector<int>s;

void sieve() {
	prime[0] = prime[1] = false;
	for (int i = 2; i < 35; i++) {
		if (!prime[i]) continue;
		for (int j = 2; i * j < 35; j++) {
			prime[i * j] = false;
		}
	}
}

void solve(int curr, int collect) {
	if (collect == N && prime[s[0] + s[N - 1]]) {
		ans.push_back(s);
		return;
	} else if (collect == N && !prime[s[0] + s[N - 1]]) return;

	for (int i = 2; i <= N; i++) {
		if (check[i] || !prime[i + curr]) continue;
		s.push_back(i); check[i] = true;
		solve(i, collect + 1);
		s.pop_back(); check[i] = false;
	}
}

int main() {
	sieve();

	while (cin >> N) {
		if (tCase) cout << '\n';	

		printf("Case %d:\n", ++tCase);
		ans.clear(); s.clear();
		
		s.push_back(1);
		solve(1, 1);
		
		for (int i = 0; i < (int) ans.size(); i++) {
			for (int j = 0, len = (int) ans[i].size(); j < len; j++) {
				cout << ans[i][j];
				if (j + 1 < len) cout << " ";
			}
			cout << endl;
		}
	} 
	return 0;
}

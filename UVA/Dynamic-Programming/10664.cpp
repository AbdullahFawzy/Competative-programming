#include <bits/stdc++.h>
 
using namespace std;

int T, S;
string s;
vector<int>n;
int dp[30][210];

void convert(string str) {
	int len = (int) str.size();
	int num = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			n.push_back(num);
			num = 0;
		} else {
			num = (num * 10) + (int) (str[i] - '0');
		}
	}
	n.push_back(num);
}

bool solve(int id, int remW) {
	if (id >= (int) n.size()) return false;
	if (remW == 0) return true;

	if (~dp[id][remW]) return dp[id][remW];
	if (remW - n[id] < 0) return dp[id][remW] = solve(id + 1, remW);

	return dp[id][remW] = max(solve(id + 1, remW), 
							solve(id + 1, remW - n[id]));
}

int main() {
	cin >> T; cin.ignore();
	while (T--) {
		getline(cin, s);
		n.clear(); S = 0;
		convert(s);
		for (int i = 0; i < (int) n.size(); i++) {
			S += n[i];
		}
		memset(dp, -1, sizeof dp);

		if (S % 2 != 0 || !solve(0, (S + 1) / 2))
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

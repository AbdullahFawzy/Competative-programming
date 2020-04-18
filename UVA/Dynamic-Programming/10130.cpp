#include <bits/stdc++.h>

using namespace std;

int T, N, G, MW;
int A[1005], B[1005];
int dp[1005][35];

int solve(int id, int remW) {
	if (id == N) return 0;
	if (remW == 0) return 0;

	if (~dp[id][remW]) return dp[id][remW];
	
	if (B[id] > remW)
		dp[id][remW] = solve(id + 1, remW);
	
	else dp[id][remW] = max(dp[id][remW], 
						max(solve(id + 1, remW), A[id] + solve(id + 1, remW - B[id])));

	return dp[id][remW];
}

int main() {
	cin >> T;
	while (T--) {
		int sol = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i];
		}

		memset(dp, -1, sizeof dp);

		cin >> G;
		for (int i = 0; i < G; i++) {
			cin >> MW;
			sol += solve(0, MW);
		}
		cout << sol << endl;
 	}
}
#include <bits/stdc++.h>

using namespace std;

int T, N, W;
int A[110], B[110];
long long int dp[110][100005];

long long int solve(int id, int remW) {
	if (id == N || remW == 0) return 0;

	if (~dp[id][remW]) return dp[id][remW];
	if (remW < A[id]) return dp[id][remW] = solve(id + 1, remW);

	return dp[id][remW] = max(solve(id + 1, remW), 
						B[id] + solve(id + 1, remW - A[id]));
}

int main() {
	cin >> N >> W;
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];

	memset(dp, -1, sizeof dp);
	cout << solve(0, W) << endl;		
}

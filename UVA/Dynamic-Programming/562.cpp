#include <bits/stdc++.h>

using namespace std;

int T, N, S;
int A[110];
int dp[110][25010];

int solve(int id, int W) {
	if (W > S) return 0;
	if (id == N || W == S) return W;

	if (~dp[id][W]) return dp[id][W];

	if (W + A[id] > S) return dp[id][W] = solve(id + 1, W);
	return dp[id][W] = max(solve(id + 1, W), solve(id + 1, W + A[id]));
}

int main() {
	cin >> T;
	while (T--) {
		int sum = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}

		S = (sum + 1) / 2;
		memset(dp, -1, sizeof dp);
		
		int valA = solve(0, 0);
		int valB = sum - valA;

		cout << abs(valA - valB) << endl;
 	}
}
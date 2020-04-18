#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N, K;
int H[100005];
int dp[100001];

int main() {
	cin >> N >> K; 
	H[0] = INT32_MAX; // to avoid RTE
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = 0; i <= N; i++) dp[i] = INT32_MAX;
	int ans = 0;
	
	dp[N] = 0; // the base case
	K = min(N - 1, K);
	
	for (int i = N; i > 1; i--) {
		for (int j = 1; j <= K; j++) {
			if (i - j < 0) break;
			dp[i - j] = min(dp[i - j], abs(H[i] - H[i - j]) + dp[i]);
		}
	}

	cout << dp[1] << endl;

	return 0;
}
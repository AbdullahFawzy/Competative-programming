#include <bits/stdc++.h>
 
using namespace std;

int t, w, N;
int A[40], B[40];
int dp[40][1100];
int path[40][1100];
vector<int>ans;

int solve(int i, int T) {
	if (i >= N) return 0;

	if (~dp[i][T]) return dp[i][T];

	int tt = 3 * A[i] * w;
	int a = 0, b = 0;

	if (T + tt <= t)
		a = B[i] + solve(i + 1, T + tt);
	b = solve(i + 1, T);

	if (a > b) path[i][T] = 1;
	else path[i][T] = 2;
	
	return dp[i][T] = max(a, b);
} 
	
int print_path(int i, int T) {
	if (path[i][T] == -1) return 0;

	if (path[i][T] == 1) {
		ans.push_back(i);
		return 1 + print_path(i + 1, T + (3 * w * A[i]));
	} else {
		return print_path(i + 1, T);
	}
}

int main() {
	bool test = 0;

	while (scanf("%d %d", &t, &w) != EOF) {
		cin >> N;
		if (test == 1) printf("\n");
		test = 1;
		ans.clear();
		for (int i = 0; i < N; i++) {
			cin >> A[i] >> B[i];
		}


		memset(dp, -1, sizeof dp);
		memset(path, -1, sizeof path);

		cout << solve(0, 0) << endl;
		cout << print_path(0, 0) << endl;

		for (int i = 0; i < (int) ans.size(); i++) {
			cout << A[ans[i]] << " " << B[ans[i]] << endl;
		}
	}
	return 0;
}

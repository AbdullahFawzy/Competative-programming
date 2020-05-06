#include <bits/stdc++.h>

using namespace std;

#define F 	first
#define S 	second
#define ll 	long long int

int main() {
	int n, m, c = 0;
	bool test = 0;
	while (cin >> n, n != -1) {
		if (test) printf("\n");
		test = true;
		vector<int> a;
		a.push_back(n);

		while (cin >> m, m != -1) a.push_back(m);

		int len = (int) a.size(), ans = 1;
		vector<int>dp(len, 1);

		for (int i = 1; i < len; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] <= a[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
				ans = max(ans, dp[i]);
			}
		}
		printf("Test #%d:\n", ++c);
		printf("  maximum possible interceptions: %d\n", ans);
	}
	return 0;
}

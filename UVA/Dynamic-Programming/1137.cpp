#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define F 	first
#define S 	second

int main() {
	const int max_amount = 10000;

	vector<int> coins;
	for (int i = 1; (i*i*i) < 9262; i++) coins.push_back(i*i*i);
	int len = (int) coins.size();

	vector<vector<ll>> dp(len + 1, vector<ll>(max_amount + 1, 0));

	for (int i = 0; i <= len; i++) dp[i][0] = 1;
	for (int i = 1; i <= max_amount; i++) dp[0][i] = 0;

	for (int i = 1; i <= len; i++) {
		for (int curr_amount = 1; curr_amount <= max_amount; ++curr_amount) {
			if (coins[i - 1] > curr_amount) dp[i][curr_amount] = dp[i - 1][curr_amount];
			else dp[i][curr_amount] = dp[i - 1][curr_amount] + dp[i][curr_amount - coins[i - 1]];		
		}
	} 

	int n;
	while (cin >> n) {
		cout << dp[len][n] << endl;
	}
	return 0;
}
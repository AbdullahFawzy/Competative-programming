#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define F 	first
#define S 	second

int main() {
	const int max_amount = 7489;
	const int len = 5;

	vector<int> coins{1, 5, 10, 25, 50};
	vector<vector<int>> dp(len + 1, vector<int>(max_amount + 1, 0));

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
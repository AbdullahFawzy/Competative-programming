#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define F 	first
#define S 	second
int main() {
	const int max_amount = 30001;
	vector<int>coins{10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
	int len = (int) coins.size();
	vector<vector<ll>> dp(len + 1, vector<ll>(max_amount, 0));

	for (int i = 0; i <= len; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= max_amount; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= len; i++) {
		for (int curr_amount = 1; curr_amount <= max_amount; curr_amount++) {
			if (coins[i - 1] > curr_amount) dp[i][curr_amount] = dp[i - 1][curr_amount];
			else dp[i][curr_amount] = dp[i - 1][curr_amount] + dp[i][curr_amount - coins[i - 1]];
		}
	}

	double damount;
	while (cin >> damount, damount != 0.00) {
		int amount = damount * 100.0;
		if (double(amount / 100.0) != damount) amount++;

		cout << setprecision(2) << fixed;
		cout << setw(6) << right << damount;
		cout << setw(17) << right << dp[len][amount] << endl;
 	}
	return 0;
}
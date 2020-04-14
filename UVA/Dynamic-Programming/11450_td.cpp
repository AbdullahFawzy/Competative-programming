#include <bits/stdc++.h>
 
using namespace std;

int T;
int M, C;
int prices[25][25];
int memo[205][25];


int solve(int money, int g) {
	if (money < 0) return INT32_MIN;
	if (memo[money][g] != -1) return memo[money][g];
	if (g == C) return M - money;

	int& ans = memo[money][g];
	for (int i = 1; i <= prices[g][0]; i++) {
		ans = max(ans, solve(money - prices[g][i], g + 1));
	}
	return ans;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &M, &C);
		for (int i = 0; i < C; i++) {
			scanf("%d", &prices[i][0]);
			for (int j = 1; j <= prices[i][0]; j++) {
				scanf("%d", &prices[i][j]);
			}
		}

		memset(memo, -1, sizeof memo);

		int sol = solve(M, 0);
		if (sol < 0) printf("no solution\n");
		else printf("%d\n", sol);
	}
	return 0;
}
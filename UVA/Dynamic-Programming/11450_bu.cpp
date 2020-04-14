#include <bits/stdc++.h>
 
using namespace std;

int T;
int M, C;
int prices[25][25];
bool reachable[5][205];

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

		memset(reachable, 0, sizeof reachable);

		int curr = 0, prev = 1;
		for (int i = 1; i <= prices[0][0]; i++) {
			if (M - prices[0][i] >= 0)  {
				reachable[curr][M - prices[0][i]] = true;
			}
		}

		for (int i = 1; i < C; i++) {
			swap(curr, prev);

			for (int k = 0; k < M; k++)
				reachable[curr][k] = 0; // reseting the value to 0.

			for (int money = 0; money < M; money++) {
				if (reachable[prev][money]) {
					for (int j = 1; j <= prices[i][0]; j++) {
						if (money - prices[i][j] >= 0) {
							reachable[curr][money - prices[i][j]] = true;
						}
					}
				}
			}
		}

		int money = 0;
		for (money = 0; money <= M && !reachable[curr][money]; money++);

		if (money == M + 1)
			printf("no solution\n");
		else printf("%d\n", M - money);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int M, N;
pair<int, int>P[3];

int main() {

	while (cin >> M >> N, M != 1 || N != 1) {
		P[0] = {0, 1};
		P[1] = {1, 0};
		P[2] = {1, 1};

		while (!(P[2].F == M && P[2].S == N)) {
			// if (P[2].F > M || P[2].S > N) break;
			if (P[2].F * N > P[2].S * M) {
				printf("L");
				P[1] = {P[2].F, P[2].S};
			} else {
				printf("R");
				P[0] = {P[2].F, P[2].S};
			}
			P[2].F = P[0].F + P[1].F;
			P[2].S = P[0].S + P[1].S;
		}
		printf("\n");
	}
	return 0;
}
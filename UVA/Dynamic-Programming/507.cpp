#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N, R;
int A[20005];

int main() {
	scanf("%d", &N);

	for (int t = 1; t <= N; t++) {
		scanf("%d", &R);
		for (int i = 0; i < R - 1; i++) {
			scanf("%d", &A[i]);
		}

		int ans = 0;
		int sum = 0, i = 1, j = 0, lj = 0, li = 0;
		for (int k = 0; k < R - 1; k++) {
			sum += A[k];
			sum = sum < 0? 0 : sum;
			ans = max(ans, sum);
		}

		sum = 0;
		for (int k = 0; k < R - 1; k++) {
			sum += A[k];
			if (sum < 0) {
				i = j = k + 2;
				j = k + 2;
				sum = 0;
			} 
			if (sum == ans) {
				j = k + 2;
				
				if (j - i + 1 > lj - li + 1) {
					lj = j;
					li = i;
				}
			}
		}

		if (ans == 0) printf("Route %d has no nice parts\n", t);
		else printf("The nicest part of route %d is between stops %d and %d\n", t, li, lj);
	}
	return 0;
}
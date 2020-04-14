#include <bits/stdc++.h>
 
using namespace std;

int N;
int A[10005];

int main() {
	while (cin >> N, N != 0) {
		int ans = 0, sum = 0;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i] >= 0 || -A[i] <= sum? A[i] : -sum;
			ans = max(sum, ans);
		}

		if (ans)
			printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}
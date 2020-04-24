#include <bits/stdc++.h>
 
using namespace std;

int N, M, Q, c;
int A[1010];

int main() {
	while (cin >> N, N != 0) {
		for (int i = 0; i < N; i++) cin >> A[i];
		cin >> M;
		printf("Case %d:\n", ++c);

		for (int i = 1; i <= M; i++) {
			int ans = A[0] + A[1]; cin >> Q;
		
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (k == j) continue;
					if (abs((A[j] + A[k]) - Q) < abs(ans - Q))
						ans = A[j] + A[k];
				}
			}

			printf("Closest sum to %d is %d.\n", Q, ans);
		} 
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N, D, R, ans;
int A[105], B[105];

int main() {
	while (cin >> N >> D >> R, N + D + R != 0) {
		ans = 0;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < N; i++) cin >> B[i];

		sort(A, A + N);
		sort(B, B + N, greater<int>());

		for (int i = 0; i < N; i++) {
			ans += A[i] + B[i] > D? ((A[i] + B[i]) - D) * R : 0;
		}

		printf("%d\n", ans);
	}
	return 0;
}
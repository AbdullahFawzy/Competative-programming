#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N, M;
pair<int, int> ans;
int D;
vector<int>A(10005);

int main() {
	while (scanf("%d", &N) != EOF) {
		D = INT32_MAX;
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		scanf("%d", &M);
		sort(A.begin(), A.begin() + N);

		for (int i = N - 1; i >= 0; i--) {
			int target = M - A[i];
			auto it = lower_bound(A.begin(), A.begin() + i - 1, target);


			if (target == *it) {
				if (D > abs(target - A[i])) {
					D = abs(target - A[i]);
					ans.F = min(A[i], target);
					ans.S = max(target, A[i]);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", 
			ans.F, ans.S);
		cin.ignore();
	}
	return 0;
}
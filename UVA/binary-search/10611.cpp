#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N, Q, T;
vector<int> A(50005);

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &T);
		auto lo = lower_bound(A.begin(), A.begin() + N, T);
		auto up = upper_bound(A.begin(), A.begin() + N, T);

		while (*lo >= T || lo == A.begin() + N) --lo;
		while (*up <= T && up != A.begin() + N) ++up;

		if (*lo == 0)
			printf("X ");
		else 
			printf("%d ", *lo);
		
		if (*up == 0)
			printf("X\n");
		else 
			printf("%d\n", *up);
	}
	return 0;
}
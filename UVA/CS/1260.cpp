#include <bits/stdc++.h>

using namespace std;

#define F 	first
#define S 	second
#define ll 	long long int

int T, N, C;
int A[1010];

int main() {
	cin >> T;
	while (T--) {
		cin >> N; C = 0;

		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 1; i < N; i++) 
			for (int j = 0; j < i; j++) 
				C = A[j] <= A[i]? ++C : C;
		
		printf("%d\n", C);
	}
	return 0;
}
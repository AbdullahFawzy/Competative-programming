#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int T, N;
int A[100005];
int B[100005];

int main() {
	cin >> T;
	int t = 0;
	while (T--) {
		int ans = 0;
		int tans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			
			if (i != 0) {
				
				B[i] = A[i] - A[i - 1];
				if (B[i] > ans) {
					ans = B[i];
					tans = ans - 1;
				} else if (B[i] <= ans && B[i] > tans) {
					++ans;
					tans = ans;
				} else if (B[i] == tans)
					tans--;
			} else {
				ans = A[i];
				tans = A[i] - 1;
			}
		}
		printf("Case %d: %d\n", ++t,  ans);
	}
	return 0;
}
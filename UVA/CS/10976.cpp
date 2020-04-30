#include <bits/stdc++.h>

using namespace std;

#define F 	first
#define S 	second
#define ll 	long long int

int N, C;
ll M, D;
vector<pair<ll, ll>> ans;

int main() {
	while (cin >> N) {
		M = N; C = 0;
		ans.clear();

		do {
			++M;
			double n = M - N; 
			D = (M * N) / n;
			
			double n2 = D + M;
			int D2 = (D * M) / n2;
			
			if (D2 == N) {
				++C;
				ans.push_back({D, M});
			}
		} while (M != D);

		printf("%d\n", C);
		for (int i = 0; i < C; i++) {
			printf("1/%d = 1/%lld + 1/%lld\n", N, ans[i].F, ans[i].S);
		}
	}
	return 0;
}
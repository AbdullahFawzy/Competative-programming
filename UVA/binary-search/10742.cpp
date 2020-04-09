#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int N;
vector<bool>check(1000005, 1);
vector<int>prime;

void sieve() {
	for (int i = 2; i <= 1000001; i++) {
		if (!check[i]) continue;
		prime.push_back(i);
		for (int j = 2; j * i <= 1000001; j++) {
			check[i*j] = 0;
		}
	}
}

int binarySearch(int target) {
	int l = 0, r = (int) prime.size();

	while (l < r) {
		int mid = (l + r) / 2;
		if (prime[mid] > target) r = mid - 1;
		else l = mid + 1;
	}

	return l;
}

int main() {
	sieve();
	int t = 0;

	while (scanf("%d", &N), N != 0) {
		if (N < 5) {
			printf("Case %d: %d\n", ++t, 0);
			continue;
		}
		int ind = binarySearch(N);
		while (N - prime[ind] <= 1 ||
			ind == (int) prime.size()) --ind;
		
		unsigned long long int ans = 0;
		int i = 1;
		while (ind != -1) {
			if (N - prime[ind] > prime[ind]) {
				ans += ind;
			} else {
				int x = binarySearch(N - prime[ind]);
				while (prime[ind] + prime[x] > N || ind == x) --x;
				ans += x + 1;
			}
			--ind;
		}
		printf("Case %d: %llu\n", ++t, ans);
	}

	return 0;
}
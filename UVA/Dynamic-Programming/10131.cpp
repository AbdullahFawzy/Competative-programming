#include <bits/stdc++.h>

using namespace std;

#define F 	first
#define S 	second
#define ll 	long long int

bool smaller(pair<pair<int, int>, int>& a, 
			pair<pair<int, int>, int>& b) {
	return a.F.F < b.F.F;
}

int main() {
	vector<pair< pair<int, int>, int>> vec;
	int a, b, i = 0;
	while (cin >> a >> b) vec.push_back({{a, b}, ++i});

	sort(vec.begin(), vec.end(), smaller);
	a = (int) vec.size();

	vector<pair<int, int>> dp(a, {1, -1});
	int ans = 1, ind = -1;
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i].F.F > vec[j].F.F && vec[i].F.S < vec[j].F.S) {
				if (dp[i].F < dp[j].F + 1)
					dp[i] = {dp[j].F + 1, j};
				
				if (ans <= dp[i].F) {
					ans = dp[i].F;
					ind = i;
				}
			}
		}
	}

	vector<int> fans(ans, 0);
	printf("%d\n", ans);
	while (dp[ind].S != -1) {
		fans[--ans] = vec[ind].S; 
		ind = dp[ind].S;
	}
	fans[0] = vec[ind].S;

	for (int i = 0; i < fans.size(); i++) {
		printf("%d\n", fans[i]);
	}
	return 0;
}
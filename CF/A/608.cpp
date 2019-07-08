#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int n, s, f, t;
	int ans = 0;
	pair<int, int>pr[105];

	scanf("%d %d", &n, &s);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &f, &t);
		pr[i] = make_pair(f, t);
	}

	sort(pr, pr+n);
	for(int i=n-1; i>=0; i--) {
		if(i == n-1) 
			ans += s - pr[i].first;
		else 
			ans += pr[i+1].first - pr[i].first;

		if(ans < pr[i].second) 
			ans += pr[i].second - ans;
	}
	ans += pr[0].first;
	printf("%d\n", ans);
	return 0;
}
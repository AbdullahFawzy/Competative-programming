#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int main() {
	int n, f;
	long long ans = 0;
	vector<pair<int, int>>vec;
	vector<pair<int, int>>val;

	scanf("%d %d", &n, &f);
	for(int i=0; i<n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back(make_pair(min(a, b), min(2*a, b)));
		val.push_back(make_pair(vec[i].second - vec[i].first, i));
	}
	sort(val.begin(), val.end(), greater<pair<int,int>>());

	int	i = 0;
	while(f--) {
		ans += vec[val[i].second].second;
		vec[val[i].second] = make_pair(0, 0);
		++i;
	}

	for(int i=0; i<n; i++) {
		ans += vec[i].first;
	}
	printf("%lld\n", ans);

	return 0;
}
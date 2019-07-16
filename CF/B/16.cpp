#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int main() {
	int n, m;
	vector<pair<int, int>> vec;

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back(make_pair(b, a));
	}

	sort(vec.begin(), vec.end(), greater<pair<int, int>>());
	int total = 0;

	for(int i=0; i<vec.size(); i++) {
		if(vec[i].second <= n) {			
			total += vec[i].first * vec[i].second;
			n -= vec[i].second;
		} else if(vec[i].second > n) {
			total += n * vec[i].first;
			break;
		}
		if(!n) break;
	}

	printf("%d\n", total);

	return 0;
}
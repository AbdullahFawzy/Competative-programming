#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int n, d, arr[105], m;
	int ans = 0;

	scanf("%d %d", &n, &d);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		if(i < n) ans += arr[i];
		else ans -= d;
	}

	printf("%d\n", ans);
	return 0;
}
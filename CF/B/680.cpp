#include <iostream>
#include <cstring>

using namespace std;
int main() {
	int n, a, crim = 0, ans = 0;
	int arr[105];
	memset(arr, 0, sizeof(arr));

	scanf("%d %d", &n, &a);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		if(arr[i]) ++crim;
	}

	for(int i=0; i<a; i++) {
		int dist = abs(a-(i+1));
		if(a+dist-1 > n-1) continue; 
		if(arr[a+dist-1] == arr[i] && arr[i]) {
			crim -= a-1 == i? 1:2;
			ans += a-1 == i? 1:2;
		} else if(arr[a+dist-1] || arr[i]) {
			--crim;
		}
	}

	printf("%d\n", ans+crim);
}
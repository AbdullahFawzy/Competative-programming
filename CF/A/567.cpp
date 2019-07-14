#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
	int n;
	int arr[100005];

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	for(int i=0; i<n; i++) {
		int maxi = arr[n-1] - arr[i];
		int mini = 2e9+5;
		if(i+1 != n)
			mini = arr[i+1] - arr[i];

		maxi = max(maxi, arr[i] - arr[0]);
		if(i != 0)
			mini = min(mini, arr[i] - arr[i-1]);
		printf("%d %d\n", mini, maxi);
	}
	return 0;
}
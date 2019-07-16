#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int main() {
	int n, ans = 0;
	int arr[1005], sum[1005];

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<n; i++) {
		int total = 0;
		for(int j=i+1; j<n; j++) {
			if(arr[j-1] >= arr[j]) ++total;
			else break;
		}

		sum[i] = total + 1;
		if(arr[i-1] < arr[i]) sum[i] += sum[i-1];
		else if(arr[i-1] == arr[i] && i != 0) sum[i] = sum[i-1];
		ans = max(sum[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}
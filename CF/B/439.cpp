#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int main() {
	int n, x;
	unsigned long long int hours = 0;
	int arr[100005];

	scanf("%d %d", &n, &x);
	for(int i=0; i<n; i++) 
		scanf("%d", &arr[i]);

	sort(arr, arr+n);
	for(int i=0; i<n; i++) {
		hours += (unsigned long long int)arr[i] * x;
		if(x > 1) --x;
	}

	printf("%llu\n", hours);
	return 0;
}
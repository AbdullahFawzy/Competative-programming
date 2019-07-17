#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;
int main() {
	int n, money = 0;
	int arr[100005];
	memset(arr, 0, sizeof(arr));

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
		money = max(money, arr[i]);
	}
	printf("%d\n", money);
	
	return 0;
}
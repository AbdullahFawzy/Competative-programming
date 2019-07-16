#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int main() {
	int n, space = 0, target = 0;
	int arr[100005];
	bool check[100005];
	memset(check, 0, sizeof(check));

	scanf("%d", &n);
	target = n;

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<n; i++) {
		if(arr[i] != target) {
			check[arr[i]] = 1;
			++space;
		} else {
			check[arr[i]] = 1;
			while(check[target]) {
				printf("%d ", target);
				--target;
			}
			printf("\n");
		}
		if(space){
			printf("\n");
			--space;
		}
	}
	return 0;
}
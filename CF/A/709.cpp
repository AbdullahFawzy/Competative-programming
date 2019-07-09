#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
	int n, b, d, size;
	int sum = 0, ans = 0;

	scanf("%d %d %d", &n, &b, &d);
	for(int i=0; i<n; i++){
		scanf("%d", &size);
		if(size <= b){
			sum += size;
		}
		if(sum > d){
			++ans;
			sum = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
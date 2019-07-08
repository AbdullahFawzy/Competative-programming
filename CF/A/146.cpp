#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, counter[4] = {0, 0, 0, 0};
	string str;

	scanf("%d", &n);
	cin >> str;
	for(int i=0; i<n; i++) {
		if(i < n/2) {
			counter[0] += str[i] == '4'? 1:0;
			counter[1] += str[i] == '7'? 1:0;
		} else {
			counter[2] += str[i] == '4'? 1:0;
			counter[3] += str[i] == '7'? 1:0;		
		}
	}
	if(counter[0] == counter[2] && counter[1] == counter[3]) {
		printf("%s\n", counter[0]+counter[1]+counter[2]+counter[3] == n? "YES":"NO");
	} else printf("NO\n");
	return 0;
}
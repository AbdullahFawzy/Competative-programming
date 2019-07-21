#include <iostream>

using namespace std;

int n, m, k, pos = 1, check = 0;
bool h[1000005];

int main() {

	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++){
		int a;
		scanf("%d", &a);
		h[a] = 1;
	}

	for(int i=0; i<k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(h[pos]) check = 1;
		if(a == pos && !check) pos = b;
		else if(b == pos && !check) pos = a;
	}

	printf("%d\n", pos);
	return 0;
}
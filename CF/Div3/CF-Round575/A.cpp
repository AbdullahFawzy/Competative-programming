#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
unsigned long long int a, b, c;
 
int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		cin >> a >> b >> c;
		printf("%llu\n", (a+b+c)/2);
	}
	return 0;
}
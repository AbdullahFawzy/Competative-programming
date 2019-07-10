#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
	int n, k;
	string str = "";

	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++)
		str += 'a' + i;
	for(int i=0; i<n-k; i++) {
		str += str[i%k];
	}
	cout << str << endl;
	return 0;
}
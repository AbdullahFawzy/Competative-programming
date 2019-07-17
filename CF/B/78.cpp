#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;
int main() {
	int n, counter = 4;
	char color[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		if(n - i - 1 >= 3) {
			printf("%c", color[i%4]);
		}
		else {
			printf("%c", color[counter]);
			++counter;
		}
	}
	printf("\n");
	
	return 0;
}
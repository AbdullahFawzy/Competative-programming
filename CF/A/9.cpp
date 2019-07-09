#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	int y, w;
	int ans = 0, d = 6;

	scanf("%d %d", &y, &w);
	ans = max(y, w);
	ans = d - ans + 1;

	while(d % 3 == 0 && ans % 3 == 0 && ans != 0) {
		d /= 3;
		ans /= 3;
	}
	while(d % 2 == 0 && ans % 2 == 0 && ans != 0) {
		d /= 2;
		ans /= 2;
	}
	printf("%d/%d\n", ans, d);
	return 0;
}
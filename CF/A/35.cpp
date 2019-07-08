#include <iostream>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int pos, a, b;

	scanf("%d", &pos);
	for(int i=0; i<3; i++) {
		scanf("%d %d", &a, &b);
		pos = a == pos? b:b == pos? a:pos;
	}
	fclose(stdin);

	freopen("output.txt", "w", stdout);
	printf("%d\n", pos);
	return 0;
}
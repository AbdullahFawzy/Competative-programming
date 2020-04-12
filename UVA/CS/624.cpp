#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define ull 	unsigned long long
#define sf(n) 	scanf("%d", &n)
#define pf(n) 	printf("%d\n", n);

const int mod = 1000 * 1000 * 1000 + 7;

int n, t, temp;
vector<int>arr(1000), fans, var;
int tsum;
bool term;

void getTarget(int sum, int start) {
	if (start == n) {
		if (sum > tsum && sum <= t) {
			tsum = sum;
			fans = var;
		}
		return;
	}

	var.push_back(arr[start]);
	getTarget(sum + arr[start], start + 1);
	var.pop_back();
	getTarget(sum, start + 1);
}

int main() {

	while(cin >> t >> n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		getTarget(0, 0);
		
		for (int i = 0, len = int(fans.size()); i < len; i++) {
			cout << fans[i] << " ";
		}
		printf("sum:%d\n", tsum);
		tsum = -1;
	}

	return 0;
}

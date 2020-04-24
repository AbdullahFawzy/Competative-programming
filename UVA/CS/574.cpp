#include <bits/stdc++.h>

using namespace std;

#define ll 		long long
#define ull 	unsigned long long
#define sf(n) 	scanf("%d", &n)
#define pf(n) 	printf("%d\n", n)
#define pb(n)	push_back(n)

const int mod = 1000 * 1000 * 1000 + 7;

int t, n, arr[15];

vector<int>sumN;
set<vector<int>> ans;
bool found;

void getSum(int sum, int i) {
	if (sum > t || i > n) return;

	if (sum == t) {
		int size = int(ans.size());
		ans.insert(sumN);

		if (size != int(ans.size())) {
			found = true;
			for (int j = 0, len = int(sumN.size()); j < len; j++) {
				cout << sumN[j];
				if(len - j != 1) cout << "+"; 
			}
			cout << endl;
		}

		return;
	}


	sumN.push_back(arr[i]);
	getSum(sum + arr[i], i + 1);
	sumN.pop_back();
	getSum(sum, i + 1);
}

int main() {

	while(cin >> t >> n, n != 0) {

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		printf("Sums of %d:\n", t);
		getSum(0, 0);
		if(!found) printf("NONE\n");

		found = 0; ans.clear();
	}
	return 0;
}
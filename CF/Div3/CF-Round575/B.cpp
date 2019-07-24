#include <bits/stdc++.h>

using namespace std;

int q;
int n, k;
int arr[200005];
vector<int>ans;
int main() {
	scanf("%d", &q);

	for(int i=0; i<q; i++) {

		int odd = 0, even = 0;
		scanf("%d %d", &n, &k);

		for(int j=0; j<n; j++) {

			scanf("%d", &arr[j]);
			if(arr[j] % 2 != 0){
				++odd;
				if(odd <= k)
					ans.push_back(j+1);
			}

		}
		if(odd < k) printf("NO\n");
		else{

			printf("YES\n");
			for(int j=0; j<k-1; j++){
				printf("%d ", ans[j]);
			}

			printf("%d\n", n);
		}
		ans.clear();
	}
	return 0;
}
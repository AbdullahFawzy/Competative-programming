#include <bits/stdc++.h>

using namespace std;

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
				else ++even;
			}

		}
		if(odd < k || (even+1)%2 == 0) printf("NO\n");
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
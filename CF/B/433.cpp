#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, type, l, r;
vector<int>arr(100005);
vector<int>sortedArr(100005);
vector<unsigned long long>costsSum;
vector<unsigned long long>minCostsSum;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		sortedArr[i] = arr[i];
	}

	// sort another list to satisfy the 2nd condition
	sort(sortedArr.begin(), sortedArr.begin()+n);

	for(int i=0; i<n; i++){
		if(i == 0){
			costsSum.push_back(arr[i]);
			minCostsSum.push_back(sortedArr[i]);
		}
		else{
			costsSum.push_back(costsSum[i-1] + arr[i]);
			minCostsSum.push_back(minCostsSum[i-1] + sortedArr[i]);
		}
	}


	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d %d", &type, &l, &r);
		unsigned long long Suminterval = 0;
		
		if(type == 1) {
			if(l != 1) // l := 1; l-2 := -1; out of range.
				Suminterval = costsSum[r-1] - costsSum[l-2];
			else Suminterval = costsSum[r-1];
		}
		else {
			if(l != 1) // l := 1; l-2 := -1; out of range.
				Suminterval = minCostsSum[r-1] - minCostsSum[l-2];
			else Suminterval = minCostsSum[r-1];
		}
		printf("%llu\n", Suminterval);
	}	
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>>numbersCount;
int arr[300005][2];
int n, a;

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for(int i=0; i<2*n; i++) {
		scanf("%d", &a);
		numbersCount[a].push_back(i+1);
	}
	fclose(stdin);

	freopen("output.txt", "w", stdout);
	for(map<int, vector<int>>::iterator it=numbersCount.begin();
		it != numbersCount.end(); it++) {
		
		vector<int> list = it->second;
		int len = (int)list.size();

		// if there is no even repetitions.
		if(len % 2 != 0) {
			fclose(stdout);
			freopen("output.txt", "w", stdout);
			printf("-1\n");
			break;	
		}

		for(int i = 0; i < len; i+=2) {
			printf("%d %d\n", list[i], list[i+1]);
		}
	}
	fclose(stdout);
	return 0;
}
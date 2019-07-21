#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
bool arr[105][105];
int counter[105];
set<int>players;
vector<int>group;

void update() {
	for(int i=0; i<(int)group.size(); i++) {
		for(int j=1; j<=n; j++) {
			if(arr[group[i]][j]){
				arr[j][group[i]] = 0;
				--counter[j];
			}
		}
	}
	group.clear();
}

int main() {

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
		++counter[a]; ++counter[b];
		players.insert(a); players.insert(b);
	}

	int repeat = 0, ans = 0;
	while(repeat != 2) {
		int tmp = (int)players.size();
		for(int i=1; i<=n; i++) {
			if(counter[i] == 1) {
				players.erase(i);
				group.push_back(i);
				counter[i] = 0;
			}
		}
		++repeat;
		if((int)players.size() != tmp){
			repeat = 0;
			update();
			++ans;
		}
	}

	printf("%d\n", ans);
	return 0;
}
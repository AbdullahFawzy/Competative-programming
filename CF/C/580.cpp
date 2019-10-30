#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
int x, y;
int validRoads;
bool visitedNode[100005];
int cost[100005];
bool cats[100005];


map<int, vector<int>>tree;

void traverseTree(const int &prevNode, const int &currNode) {

	bool leaf = true;
	visitedNode[currNode-1] = true;

	if(cats[currNode-1] || cost[prevNode-1] > m) {
		cost[currNode-1] = currNode == 1? 1:cost[prevNode-1] + 1;
	}

	int len = int(tree[currNode].size());
	for(int i = 0; i < len; i++) {
		int nextNode = tree[currNode][i];
		if(!visitedNode[nextNode-1]) {
			leaf = false;
			traverseTree(currNode, nextNode);
		}
	}

	if(leaf && cost[currNode-1] <= m){
		++validRoads;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		int cat;
		scanf("%d", &cat);
		cats[i] = cat == 0? false:true;
	}

	for(int i = 0; i < n-1; i++) {
		scanf("%d %d", &x, &y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	traverseTree(0, 1);
	printf("%d\n", validRoads);

	return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n, m;
int a, b;
map<int, vector<int>> tree;
vector<bool>visitedNode(150000, false);
set<int>vertixCount;

void getNodesInGraph(const int& currNode) {
	//printf("Current Vertix: %d\n", currNode);
	visitedNode[currNode] = true;
	int len = int(tree[currNode].size());
	vertixCount.insert(currNode);

	for(int i = 0; i < len; i++) {
		int nextNode = tree[currNode][i];
		if(!visitedNode[nextNode]) {
			getNodesInGraph(nextNode);
		}
	}

	return;
}

bool isCompleteGraph(const int& root) {
	getNodesInGraph(root);
	unsigned long long vertixCounter = int(vertixCount.size());
	unsigned long long totalEdges = vertixCounter * (vertixCounter - 1);
	unsigned long long edgesCounted = 0;

	for(auto &vertix : vertixCount) {
		edgesCounted += int(tree[vertix].size());
	}
	//printf("edges founded  = %d\n", edgesCounted/2);

	vertixCount.clear();
	return edgesCounted == totalEdges;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!tree[i].empty() && !visitedNode[i]) {
			if (!isCompleteGraph(i)) {
				return !printf("NO\n");
			}
		}
	}
	printf("YES\n");
	return 0;
}

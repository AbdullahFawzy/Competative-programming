#include <bits/stdc++.h>
 
using namespace std;

#define F first
#define S second

int T, D, Q, P;
pair<string, pair<int, int>> MLH[10010];

int main() {
	cin >> T;
	bool tCase = false;

	while (T--) {
		if (tCase) cout << '\n';
		tCase = true;

		cin >> D;
		for (int i = 0; i < D; i++) 
			cin >> MLH[i].F >> MLH[i].S.F >> MLH[i].S.S;
		
		cin >> Q;
		for (int i = 0; i < Q; i++) {
			int ind = -1;
			cin >> P;
		
			for (int j = 0; j < D; j++) {
				if (MLH[j].S.F <= P && MLH[j].S.S >= P) {
					if (~ind) {
						ind = -1;
						break;
					}
					ind = j;
				}
			}

			if (~ind) 
				cout << MLH[ind].F << '\n';
			else cout << "UNDETERMINED\n";
		}
	}
	return 0;
}

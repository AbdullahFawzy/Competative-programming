// The worst code i have ever written

#include <bits/stdc++.h>

using namespace std;

#define F 	first
#define S 	second
#define ll 	long long int

void strToInt(int& n, string temp) {
	for (int i = 0, len = (int) temp.size(); i < len; i++) {
		n = (n * 10) + int(temp[i] - '0'); 
	}
}

void vstrToInt(vector<int>& vec, string temp) {
	string curr = "";
	int num = 0;

	for (int i = 0, len = (int) temp.size(); i < len; i++) {
		if (temp[i] == ' ') {
			if (curr.size() != 0) {
				strToInt(num, curr);
				vec.push_back(num);
			}
			curr = ""; num = 0;
		} else {
			curr += temp[i];
		}
	}
	strToInt(num, curr);
	vec.push_back(num);
}

int main() {

	int n = 0;
	string temp;
	vector<int> m;
	unordered_map<int, int> a;
	
	while (1) {
		int s = 0;
		if (getline(cin, temp).eof()) break;
		for (int i = 0, len = (int) temp.size(); i < len; i++) {
			if (temp[i] == ' ') ++s;
		}
		
		if (s == 0) {
			a.clear(); m.clear(); n = 0;
			strToInt(n, temp);

			getline(cin, temp);
			vstrToInt(m, temp);
			for (int i = 0; i < n; i++) { a[i + 1] =  m[i];}

			getline(cin, temp);
		}
		vector<int> b, c(n + 1), dp(n + 1, 1);
		vstrToInt(b, temp);

		for (int i = 0; i < n; i++)
			c[b[i]] = i + 1;

		for (int i = 1; i <= n; i++) 
			c[i] = a[c[i]];

		int ans = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (c[j] < c[i]) dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}
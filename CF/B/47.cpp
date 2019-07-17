#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

string fix(string str) {
	reverse(str.begin(), str.end());
	str[1] = '>';
	return str;
}

int main() {
	string str[3];
	int n = 3;
	bool check[3];
	memset(check, 0, sizeof(check));

	for(int i=0; i<n; i++) {
		cin >> str[i];
		if(str[i][1] == '<')
			str[i] = fix(str[i]);
	}

	int total = 0;  
	char cur_char = 'A';

	string ans = "";
	while(total != 27) { // worst case is 3*3*3
		int counter = 0;
		for(int i=0; i<n; i++) {
			if(str[i][2] != cur_char+(total%3))
				++counter;
		}

		if(counter == 3 && !check[cur_char + (total%3) - 'A']) {
			ans += cur_char + (total%3);
			for(int i=0; i<n; i++) {
				if(str[i][0] == cur_char+(total%3))
					str[i] = "...";
			}
			counter = 0;
			check[cur_char + (total%3) - 'A'] = 1;
		}
		++total;
		if(ans.size() == 3) break;
	}

	reverse(ans.begin(), ans.end());
	if((int)ans.size() == 3)
		cout << ans << endl;
	else
		printf("Impossible\n");
	return 0;
}
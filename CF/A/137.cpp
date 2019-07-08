#include <iostream>

using namespace std;
int main() {
	string str;
	int counter = 0, ans = 0;

	cin >> str;
	for(int i=0; i<(int)str.size(); i++) {
		if(str[i] == str[i+1]) ++counter;
		if(counter == 5 || str[i] != str[i+1]){
			counter = 0;
			++ans;
		}

	}

	printf("%d\n", ans);
	return 0;
}
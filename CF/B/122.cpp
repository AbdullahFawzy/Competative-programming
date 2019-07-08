#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string str;
	int counter[2] = {0, 0};

	cin >> str;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '4') ++counter[0];
		else if(str[i] == '7') ++counter[1];
	}
	if(counter[0] == 0 && counter[1] == 0) 
		printf("-1\n");
	else if(counter[0] >= counter[1])
		printf("4\n");
	else printf("7\n");
	return 0;
}
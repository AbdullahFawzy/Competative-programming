#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

string new_size(string str) {
	long long num = 0;
	string new_str = "";

	for(int i=0; i<(int) str.size(); i++){
		num += str[i] - '0';
	}
	while(num != 0) {
		new_str += '0' + (num%10);
		num /= 10;
	}
	return new_str;
}

int main() {
	string str;
	int counter = 0;

	cin >> str;
	while((int)str.size() != 1) {
		str = new_size(str);
		++counter;
	}
	printf("%d\n", counter);	
	return 0;
}
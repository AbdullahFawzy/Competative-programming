#include <algorithm>
#include <iostream>

using namespace std;

int strToInt(string s) {
	int num = 0;
	for(int i=0; i<(int)s.size(); i++) {
		num += s[i] - '0';
		if(i+1 != (int)s.size())
			num *= 10;
	}
	return num;
}

bool checkPalind(string str, string s) {
	reverse(s.begin(), s.end());
	return s == str;
}

string intToStr(int num) {
	string s = "";
	while(num != 0) {
		s += (num%10) + '0';
		num /= 10;
	}
	while((int)s.size() != 2)
		s += "0";
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	string s;
	cin >> s;

	string tmp[2] = {"", ""};
	int H = 0, M = 0;

	for(int i=0; i<5; i++) {
		if(i < 2) tmp[0] += s[i];
		if(i > 2) tmp[1] += s[i];
	}
	
	H = strToInt(tmp[0]);
	M = strToInt(tmp[1]);
	string newH = "", newM = "";
	do{
		++M;
		if(M == 60)
			++H;
		M %= 60;
		H %= 24;
		newH = intToStr(H);
		newM = intToStr(M);
	} while(!checkPalind(newH, newM));

	cout << newH << ":" << newM << endl;
	return 0;
}
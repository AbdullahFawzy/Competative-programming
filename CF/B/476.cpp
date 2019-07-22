#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int ex, prob;
string st, tr;
vector<int>val;

void checkSec(int counter, int pos) {
	for(int i=pos; i < (int)tr.size(); i++) {
		if(tr[i] == '+') ++counter;
		else if(tr[i] == '-') --counter;
		else{
			checkSec(counter+1, i+1);
			checkSec(counter-1, i+1);
			return;
		}

	}
	val.push_back(counter);
}

int main() {
	cin >> st >> tr;
	ex = count(st.begin(), st.end(), '+')
	  	- count(st.begin(), st.end(), '-');
	checkSec(0, 0);

	for(int i=0; i<(int)val.size(); i++) {
		if(val[i] == ex) ++prob;
	}
	double form = double(prob)/int(val.size());
	printf("%.12lf\n", form);
	return 0;
}
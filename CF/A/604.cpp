#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int time[5], wa[5];
	int sHack, usHack;
	int maxPoint[5] = {500, 1000, 1500, 2000, 2500};
	double ans = 0.0;

	for(int i=0; i<5; i++) 
		scanf("%d", &time[i]);
	for(int i=0; i<5; i++) {
		scanf("%d", &wa[i]);
		ans += max(0.3*(maxPoint[i]), (1-(time[i]/250.0))*maxPoint[i]-(50*wa[i]));
	}
	scanf("%d %d", &sHack, &usHack);
	ans += sHack*100 - (usHack*50);

	printf("%.0lf\n", ans);
	return 0;
}
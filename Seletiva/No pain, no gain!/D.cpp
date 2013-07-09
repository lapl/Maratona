#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main () {
	map<int,int> alice;
	map<int,int> beatriz;
	int a, b, dif1, dif2, x;
	scanf("%d %d", &a, &b);
	while(a) {
		alice.clear();
		beatriz.clear();
		dif1 = 0;
		dif2 = 0;
		while (a--) {
			scanf("%d", &x);
			alice[x] = 1;
		}
		while(b--) {
			scanf("%d", &x);
			beatriz[x] = 1;
		}
		map<int,int>::iterator it;
		for (it = alice.begin(); it != alice.end(); it++) {
			int i = (*it).first;
			if (!beatriz.count(i)) dif1++;
		}
		for (it = beatriz.begin(); it != beatriz.end(); it++) {
			int i = (*it).first;
			if (!alice.count(i)) dif2++;
		}
		printf("%d\n", min(dif1, dif2));
		scanf("%d %d", &a, &b);
	}
}


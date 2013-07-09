#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int vessels[1010];

int m,n;

bool can (int size) {
	int used = 1;
	int atual = 0;
	for(int i = 0; i < n; )  {
		atual += vessels[i];
		if(vessels[i] > size) return 0;
		if(atual <= size) ++i;
		else { ++used; atual = 0;}
	}
	return used <= m;
}

int main () {
	int lo,hi,mid,ans;
	while(scanf("%d %d",&n,&m) == 2) {
		for(int i = 0;  i < n; ++i) scanf("%d",&vessels[i]);
			lo = 0, hi = (int)(1e+9+20), mid = 0, ans = 0;
		while((hi-lo) > 1) {
			mid = (lo+hi)/2;
			if(can(mid)) { ans = mid; hi = mid; }
			else lo= mid;
		}
		printf("%d\n", ans);
	}
	return 0;
}


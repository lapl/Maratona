#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		int ans = 0;
		int aux = n;
		while(aux >= 3) {
			ans+=(aux/3);
			int resto=(aux%3);
			aux/=3;
			aux+=(resto);
		}
		int rest = aux%3;
		if(rest == 2) {
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}


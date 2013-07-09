#include <cstdio>
#include <algorithm>
#define EPS 1e-9

using namespace std;

int stalls[100010];
int t,c;

bool can (int mid) {
	int qtd = 1;
	for(int i = 1, aux = 0; i < t && qtd < c; ++i) {
		if((stalls[i] - stalls[aux]) >= mid) { ++qtd; aux = i; }
	}
	return qtd == c;
}

int main () {
	//freopen("in.txt","r",stdin);
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&t, &c);
		for(int i = 0; i < t; ++i) scanf("%d",&stalls[i]);
		sort(stalls, stalls+t);
		int hi = stalls[t-1] - stalls[0];
		int lo = 1000000020;
		for(int i = 1; i < t; ++i) lo = min(lo, stalls[i] - stalls[i-1]);
		int ans = hi, mid = 0;
		for(int i = 0; i < 100; ++i) {
			mid = (hi+lo)/2;
			if(can(mid)) { ans = mid; lo = mid; }
			else hi = mid;
		}
		printf("%d\n",ans);
	}
	//while(1);
	return 0;
}


#include <cstdio>
#include <algorithm>
#include <cstring>

#define INF 1000000000

using namespace std;

int dp[5000];

char aux[15];

int main () {
	int n,m;
	while(scanf("%d %d",&n,&m) && (n|m)) {
		int end = 1<<n;
		for(int i = 0; i < end; ++i)
			dp[i]=INF;
		while(m--) {
			int x = 0;
			scanf("%s",aux);
			for(int i = n-1; i >= 0; --i) {
				if(aux[i]=='1') {
					x|=(1<<(n-i-1));
				}
			}
			int cost;
			scanf("%d",&cost);
			dp[x]=min(cost,dp[x]);
		}
		for(int i = 0; i < end; ++i)
			for(int j = (i-1)&i; j; j = (j-1)&i)
					dp[i]=min(dp[i],dp[j]+dp[i^j]);
		dp[end-1]!=INF ? printf("%d\n",dp[end-1]) : printf("-1\n");
	}
	return 0;
}


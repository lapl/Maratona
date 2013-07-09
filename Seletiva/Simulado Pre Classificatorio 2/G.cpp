#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define VAR(a,b) __typeof(b) a=(b)

int dp[80];

int main () {
	dp[1] = 1; dp[2] = 2; dp[3] = 2;
	FOR(i,4,80) dp[i] = dp[i-2] + dp[i-3];
	int n;
	while(scanf("%d",&n) == 1) {
		printf("%d\n", dp[n]);
	}
	return 0;
}


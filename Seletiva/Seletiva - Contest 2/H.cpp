#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

using namespace std;


int grid[1010][1010];
int memo[1010][1010];

bool foo(int i, int j, int k) {
	if(!memo[j][k]) return 0;
	for(int l = 0; l < i; ++l)
		for(int m = 0; m < i; ++m)
			if(!grid[l+j][m+k]) return memo[j][k] = 0;
	return memo[j][k] = 1;
}

int lol = 0;

int menor;

int N,M;

bool f(int x, int y, int n) {
	//if(n+x > menor) return 0;
	//if(n+y > menor) return 0;
	if(n + x > N) return 0;
	if(n + y > M) return 0;
	for(int i = 0; i < n; ++i)
		if(!grid[i+x][y+n-1]) { return 0; }
	for(int i = 0; i < n; ++i)
		if(!grid[x+n-1][i+y]) { return 0; }
	//cout << n << endl;
	++lol;
	return 1 + f(x,y,n+1);
}

int main () {
	int n,m;
	while(scanf("%d %d",&N,&M)) {
		if(N == 0 && M == 0) break;
		REP(i,N) REP(j,M) scanf("%d",&grid[i][j]);
		REP(i,M) grid[N+1][i] = 0;
		REP(i,N) grid[i][M+1] = 0;
		//cout << f(0,0,1) << endl;
		lol=0;
		//f(0,0,1);
		int menor = min(M,N);
		int ans=0;
		REP(i,N) REP(j,M) {
			lol = 0;
			f(i,j,1);
			ans = max(ans,lol);
		}
		printf("%d\n", ans);
	}
	return 0;
}


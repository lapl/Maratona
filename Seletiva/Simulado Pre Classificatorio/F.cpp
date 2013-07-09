#include <cstdio>
#include <algorithm>
#define FOR(i,n) for(int i = 0; i <(n); ++i)
#define INF 10000000

using namespace std;	

bool a[20][20];
bool s[20][20];
bool extra[20][20];
int n;
bool parity(int x, int y) {
	int v = 0;
	if(y < (n-1))v+=s[x][y+1];
	if(y > 0)v+=(s[x][y-1]);
	if(x > 0)v+=s[x-1][y];
	return v&1;
}


int main () {
	//freopen("in.txt","r",stdin);
	int tc;
	scanf("%d",&tc);
	for(int cases = 1; tc--;++cases) {
		scanf("%d",&n);
		int aux;
		FOR(i,n) FOR(j,n) {scanf("%d",&aux); a[i][j] = aux; } 
		int minCost = INF;
		for (int mask = 0; mask < (1<<n); ++mask) {
			FOR(i,n) s[0][n-1-i] = mask&(1<<i);
			bool ok = 1;
			FOR(i,n) {
				if(s[0][i] == 0 && (a[0][i] == 1)) { ok = 0; break; }
			}
			if(!ok) continue;
			FOR(i,n) {
				extra[0][i] = parity(0,i);
			}
			for(int i = 1; i < n && ok; ++i) FOR(j,n) {
				extra[i-1][j] = parity(i-1,j);
				if(extra[i-1][j]) { s[i][j]=1; }
				else {
					if(a[i][j]) { ok = 0; break; }
					s[i][j] = 0;
				}
			}
			FOR(i,n) if(parity(n-1,i)) { ok = 0; break; }

			if(!ok) continue;
			int cost = 0;
			FOR(i,n) FOR(j,n) cost+=(a[i][j] != s[i][j]);
			minCost = min(minCost,cost);
		}
		if(minCost == INF) minCost = -1;
		printf("Case %d: %d\n",cases, minCost);

	}
	//while(1);
	return 0;
}


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

VI adjList[111];
int fim[111];
int dist[111];

void dfs(int u) {
	if(dist[u]!=-1) return;
	
	if(SIZE(adjList[u])==0) {
		dist[u]=0;
		fim[u]=u;
		return;
	}
	
	dist[u]=0;
	fim[u]=u;
	
	REP(i,SIZE(adjList[u])) {
		int v = adjList[u][i];
		
		dfs(v);
		
		if(dist[v]+1 > dist[u]) {
			dist[u]=dist[v]+1;
			fim[u]=fim[v];
		} else if(dist[v]+1==dist[u]) {
			if(fim[v] < fim[u]) fim[u] = fim[v];
		}
	}
	
}

int main () {
	int n;
	for(int cases = 1; scanf("%d",&n) && n;++cases) {
		REP(i,n) adjList[i].clear();
		int s;
		scanf("%d",&s);
		int a,b;
		while(scanf("%d %d",&a,&b) && (a|b)) {
			adjList[a-1].PB(b-1);
		}
		CLR(dist,-1);
		dfs(s-1);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",cases,s,dist[s-1],fim[s-1]+1);
	}
	return 0;
}


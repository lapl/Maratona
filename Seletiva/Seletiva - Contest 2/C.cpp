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

VI adjList[10010];

int dist[10010];

void dfs(int u) {
	REP(i,SIZE(adjList[u])) {
		int v = adjList[u][i];
		if(dist[v]!=-1) continue;
		dist[v]=dist[u]+1;
		dfs(v);
	}
}

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		 int n;
		 scanf("%d",&n);
		 REP(i,n) adjList[i].clear();
		 REP(i,n) {
		 	int m;
		 	scanf("%d",&m);
		 	while(m--){
		 		int x;
		 		scanf("%d",&x);
		 		adjList[i].PB(x-1);
		 	}
		 }
		 memset(dist,-1,sizeof dist);
		 dist[0]=0;
		 dfs(0);
		 int maior = max_element(dist,dist+n)-dist;
		 memset(dist,-1,sizeof dist);
		 dist[maior]=0;
		 dfs(maior);
		 int diam = *max_element(dist,dist+n);
		 printf("%d\n",2*(n-1)-diam);
	}
	return 0;
}


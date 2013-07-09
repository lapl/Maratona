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
#include <queue>
#define INF 1<<30

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

struct Magic {
	int damage;
	int cost;
};

struct Galeria {
	int u,v;
};

struct Monster {
	int salao,hp;
};


Magic magics[1010];
Galeria galerias[1000010];
VI saloes[1010];
int dp[2010];
int dist[1010];
int custos[1010];

VI adjList[1010];

int main () {
	int m,n,g,k;
	while(scanf("%d %d %d %d",&m,&n,&g,&k) && m) {
		REP(i,n+1) saloes[i].clear();
		REP(i,n+1) adjList[i].clear();
		REP(i,m) scanf("%d %d",&magics[i].cost,&magics[i].damage);
		REP(i,g) { 
			int a,b;
			scanf("%d %d",&a,&b);
			adjList[a].PB(b);
			adjList[b].PB(a);
		}
		REP(i,k) { 
			int s,hp;
			scanf("%d %d",&s,&hp);
			saloes[s].PB(hp);
		}
		
		REP(i,2001) dp[i] = INF;
		dp[0]=0;
		
		REP(i,2001) REP(j,m) {
			if(i >= magics[j].damage && (dp[i - magics[j].damage] != INF)) {
				dp[i] = min(dp[i], magics[j].cost + dp[i - magics[j].damage]);
			}
		}
		
		FORD(i,1999,1) dp[i] = min(dp[i],dp[i+1]);
		
		ZERO(custos);
		FOR(i,1,n+1) {
			REP(j,SIZE(saloes[i])) custos[i]+=dp[saloes[i][j]];
			//printf("%d\n",custos[i]);
		}

		
		REP(i,n+1) dist[i] = INF;
		
		
		dist[1] = custos[1];
		
		priority_queue < PII, VII, greater<PII> > pq;
		pq.push(PII(dist[1],1));
		
		
		while(!pq.empty()) {
			PII front = pq.top(); pq.pop();
			int u = front.ND, d = front.ST;
			if(dist[u] == d) {
				REP(j,SIZE(adjList[u])) {
					int v = adjList[u][j];
					if(dist[u] + custos[v] < dist[v]) {
						dist[v] = dist[u] + custos[v];
						pq.push(PII(dist[v],v));
					}
				}
			}
		}
		dist[n] == INF ? printf("-1\n") : printf("%d\n",dist[n]);
	}
	return 0;
}


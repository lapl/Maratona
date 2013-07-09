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
#define INF 1e10
#define EPS 1e-7
typedef pair<double,double> PDD;
typedef pair<int,PDD> PIDD; //destino,temperatura,distancia

vector<PIDD> adjList[110];
double dist[110];

double sP;

int N,E,S,T;

typedef pair<double,int > PDI; //distancia, temperatura,destino

int parent[110];

VI caminho;
VI ansC;
void printPath(int u) {
	if(u == S) { caminho.PB(u); return; }
	printPath(parent[u]);
	caminho.PB(u);
}

bool can(double mid) {
	REP(i,N) dist[i] = INF;
	dist[S] = 0.0;
	parent[S]=-1;
	priority_queue<PDI, vector<PDI>, greater<PDI> > pq;
	pq.push(MP(0.0,S));
	while(!pq.empty()) {
		PDI front = pq.top(); pq.pop();
		double d = front.ST; int u = front.ND;
		if(fabs(d - dist[u]) < EPS) {
			FORE(j,adjList[u]) {
				PIDD v = *j;
				if(v.ND.ST > mid) continue;
				if(dist[u] + v.ND.ND < dist[v.ST]) {
					parent[v.ST]=u;
					dist[v.ST] = dist[u] + v.ND.ND;
					pq.push(PDI(dist[v.ST],v.ST));
				}
			}
		}
	}
	if(dist[T] != INF) {
		sP = dist[T];
		caminho = VI();
		printPath(T);
		return 1;
	}
	return 0;
}

int main () {
	while(scanf("%d %d",&N,&E) == 2) {
		REP(i,N) adjList[i].clear();
		scanf("%d %d",&S,&T);
		--S; --T;
		REP(i,E) {
			int x,y; double r,d;
			scanf("%d %d %lf %lf",&x,&y,&r,&d);
			adjList[x-1].PB(MP(y-1,MP(r,d)));
			adjList[y-1].PB(MP(x-1,MP(r,d)));
		}
		double ansT = 0.0, mid = 0.0, lo = 0.0,hi=52.0; //20 <= R <= 50
		double ansD = 0.0; //menor distancia
		sP = 0.0; //menor distancia para cada temperatura
		ansC = VI();
		REP(i,30) {//binary search the answer
			mid = (hi+lo)/2.0;
			if(can(mid)) { ansT = mid; ansD = sP; hi = mid; ansC= VI(ALL(caminho));}
			else { lo = mid; }
		}
		printf("%d",ansC[0]+1);
		FOR(i,1,SIZE(ansC)) { printf(" %d", ansC[i]+1); }
		printf("\n");
		printf("%.1lf %.1lf\n",ansD,ansT);
	}
}


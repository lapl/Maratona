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

VI pset;

void initSet(int n) {
	pset.assign(n,0);
	REP(i,n) pset[i]=i;
}

int fSet(int n) {
	return pset[n] == n ? n : pset[n] = fSet(pset[n]);
}

void unionSet(int a, int b) {
	pset[fSet(a)] = fSet(b);		
}

typedef pair<double,PII> PIII; //agora ja digitei errado vai ficar sem logica mesmo :P

vector<PIII> edgeList;

double dist2 (int px, int py, int qx, int qy) {
	return (px-qx)*(px-qx)+(py-qy)*(py-qy);
} 

vector<PII> points;

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		points.clear();
		edgeList.clear();
		REP(i,n) {
			int x,y;
			scanf("%d %d",&x,&y);
			REP(j,SIZE(points)) {
				edgeList.PB(MP(dist2(x,y,points[j].ST,points[j].ND),MP(i,j)));
			}
			points.PB(MP(x,y));
		}
		initSet(n);
		sort(ALL(edgeList));
		double mst_cost = 0;
		REP(i,SIZE(edgeList)) {
			PIII front = edgeList[i];
			if(fSet(front.ND.ND) != fSet(front.ND.ST)) {
				unionSet(front.ND.ND,front.ND.ST);
				mst_cost+=sqrt(front.ST);
			}
		}
		printf("%.2lf\n",mst_cost);
	}
	return 0;
}


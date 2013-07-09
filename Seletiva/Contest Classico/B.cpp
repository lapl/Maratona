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

typedef vector<LL> VI;
typedef pair<LL,int> PII;
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
	REP(i,n) pset[i] = i;
}

int fset(int a) {
	return (pset[a] == a ?  a : pset[a] = fset(pset[a]));
}

typedef pair<double,PII> DII;

vector<DII> edgeList;
vector<PII> points;


int main () {
	int tc;
	cin >> tc;
	while(tc--) {
		int s,p;
		cin >> s >> p;
		edgeList.clear();
		points.clear();
		REP(i,p) {
			int x,y;
			cin >> x >> y;
			REP(j,SIZE(points)) {
				int a = points[j].ST, b = points[j].ND;
				double dist = hypot(x-a,y-b);
				edgeList.PB(MP(dist,PII(i,j)));
			}
			points.PB(PII(x,y));
		}
		initSet(p);
		sort(ALL(edgeList));
		double resp = 0;
		REP(i,SIZE(edgeList)) {
			DII f = edgeList[i];
			if(fset(f.ND.ST) != fset(f.ND.ND)) {
				pset[fset(f.ND.ST)] = fset(f.ND.ND);
				resp = max(resp,f.ST);
				--p;
				if(p == s) break;
			}
		}
		printf("%.2lf\n", resp);
	}
	return 0;
}


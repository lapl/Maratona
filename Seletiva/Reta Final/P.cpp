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

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	
} A[1111];

int pset[1111];

void initSet(int n) {
	REP(i,n) pset[i]=i;
}

bool mark[1111];

int findSet(int a) {
	return (pset[a]==a) ? a : pset[a]=findSet(pset[a]);
}

void unionSet(int a, int b) {
	pset[findSet(a)]=findSet(b);
}

double dist2(PT a, PT b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main () {
	int tc;
	scanf("%d",&tc);
	for(int cases = 1; tc--; ++cases) {
		int n; double d;
		scanf("%d %lf",&n,&d);
		d*=d;
		REP(i,n) {
			scanf("%lf %lf",&A[i].x,&A[i].y);
		}
		initSet(n);
		REP(i,n) FOR(j,i+1,n) {
			if(dist2(A[i],A[j]) <= d) {
				unionSet(i,j);
			}
		}
		ZERO(mark);
		int ans = 0;
		REP(i,n) {
			if(!mark[findSet(i)]) {
				++ans;
				mark[findSet(i)]=1;
			}
		}
		printf("Case %d: %d\n",cases,ans);
	}
	return 0;
}


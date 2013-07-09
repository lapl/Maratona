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

int main () {
	int nx,ny; double w;
	while(scanf("%d %d %lf",&nx,&ny,&w)==3) {
		if(nx == 0 && ny == 0 && w == 0.0) break;
		w/=2.0;
		vector<double> v;
		REP(i,nx) {
			double x;
			scanf("%lf",&x);
			v.PB(x);
		}
		sort(ALL(v));
		bool ok = 1;
		ok&=(v[0]-w <= 0.0);
		REP(i,SIZE(v)-1) {
			double x = v[i];
			//cout << x << " " << v[i+1] << endl;
			if((x+w)<(v[i+1]-w)) { ok =0; break; }
		}
		ok&=(v[nx-1]+w >= 75.0);
		
		v.clear();
		REP(i,ny) {
			double x;
			scanf("%lf",&x);
			v.PB(x);
		}
		sort(ALL(v));
		ok&=(v[0]-w <= 0.0);
		FOR(i,1,SIZE(v)-1) {
			double x = v[i];
			if(x+w<v[i+1]-w) { ok =0; break; }
		}
		ok&=(v[ny-1]+w >= 100.0);
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}


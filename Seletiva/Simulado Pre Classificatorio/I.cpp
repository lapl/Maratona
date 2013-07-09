#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define mp make_pair
#define pb push_back
#define ALL(c) (c.begin(),c.end())
#define INF 1000000
#define EPS 1e-5
#define PI (acos(-1))
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

double volumes[10010];
int n,f;
bool can(double v) {
	//printf("%f\n", v);
	int x=0;
	FOR(i,n) {
		int lol = 0;
		x+=(volumes[i]/v);
		if(x >= f) break;
	}
	//printf("%d\n",x);
	return x >= f;
}

int main () {
	//printf("%f\n", log(100000000.0*PI/EPS)/log(2));
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&n,&f);
		++f;
		double maior = 0;
		int raio;
		FOR(i,n) { scanf("%d",&raio); volumes[i] = (double)raio*(double)raio*PI; maior = max(maior,volumes[i]); }
		double lo = 0.0, hi = maior, mid = 0.0, ans = 0.0;
		while(fabs(hi - lo) > EPS) {
			mid = (lo + hi)/2.0;
			if(can(mid)) {ans = mid; lo = mid;} 
			else { hi = mid; }
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}


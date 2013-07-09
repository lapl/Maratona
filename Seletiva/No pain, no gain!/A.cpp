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

/*int lis[1000],n;
vector<int> v;

int dolis(int z = 0) {
	REP(i,n) {
		int x = lower_bound(lis,lis+z,v[i])-lis;
		if(x==z) ++z;
		lis[x] = v[i];
	}
	return z;
}*/

LL cat[1010];

const LL mod = 1000000;

LL catalan (int n) {
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 5;
	if(cat[n]!=-1) return cat[n];
	LL sum=0;
	for(int i = 0; i < n; ++i)
		sum=sum+((catalan(i)%mod)*(catalan(n-i-1)%mod)%mod)%mod;
	return cat[n] = sum%mod;
}

int main () {
	/*while(scanf("%d",&n)==1) {
		v.assign(n,0);
		FOR(i,1,n+1) v[i-1]=i;
		int ans = 0;
		do {
			if(dolis() < 3) ++ans;
		}while(next_permutation(ALL(v))); 
		cout << ans << endl;
	}*/
	int n;
	CLR(cat,-1);
	while(scanf("%d",&n) && n) {
		printf("%lld\n",catalan(n));
	}
}


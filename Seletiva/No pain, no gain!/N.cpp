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

int coins[55];
int tables[15];

int s[4];

VI h1, h2;

int n,t;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b,a%b)); }
int lcm(int a, int b) { return (a * (b/gcd(a,b))); }

void f(int ta) {
	int height = lcm(s[0],lcm(s[1],lcm(s[2],s[3])));
	if(height > tables[ta]) { h1.PB(0); h2.PB(height); return; }
	bool b = (tables[ta]%height == 0);
	if(!b) {
		h1.PB(tables[ta]/height * height);
		h2.PB((tables[ta]/height+1) * height);
	} else {
		h1.PB(tables[ta]);
		h2.PB(tables[ta]);
	}
}

void comb(int x, int last, int ta) {
	if(x == 4) {
		f(ta);
		return;
	}
	FOR(i,last+1,n) {
		s[x]=coins[i];
		comb(x+1,i,ta);
	}
}

int main() {
	while(scanf("%d %d",&n, &t) && n) {
		REP(i,n) scanf("%d",&coins[i]);	
		REP(i,t) scanf("%d",&tables[i]);
		
		REP(i,t) {
			h1.clear(); h2.clear();
			comb(0,-1,i);
			sort(ALL(h1),greater<int>());
			sort(ALL(h2));
			printf("%d %d\n",h1[0], h2[0]);
		}
	}
  	return 0;
}


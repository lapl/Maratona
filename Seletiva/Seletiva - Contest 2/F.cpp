#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

using namespace std;

long long x,y,d;

void extendedEuclid(long long a, long long b) {
	if(b == 0) {x = 1; y = 0; d = a; return;}
	extendedEuclid(b,a%b);
	int x1 = y;
	int y1 = x-(a/b)*y;
	x = x1;
	y = y1;
}

int gcd(long long a, long long b) { return (b==0?a:gcd(b,a%b));}

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		double X,K;
		scanf("%lf %lf",&X,&K);
		long long a = (long long)floor(X/K);
		long long b = (long long)ceil(X/K);
		//printf("%lld %lld\n", a,b);
		extendedEuclid(a,b);
		x*=(X/gcd(a,b));
		y*=(X/gcd(a,b));
		printf("%lld %lld\n", x,y);
	}
	return 0;
}


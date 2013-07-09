#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <map>
#include <cmath>
#define isLetter(ch) (((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z'))
using namespace std;

#define ST first
#define ND second
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FORED(a,b) for(VAR(a,(b).rbegin());a!=(b).rend();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(a) ((int)((a).size()))
char line[1024];
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		LL x,y,n;
		scanf("%lld %lld %lld",&x,&y,&n);
		LL ans = 1;
		LL base = x;
		while(y) {
			if(y & 1) ans = ((ans%n)*(base%n))%n;
			base = ((base%n)*(base%n)%n);
			y>>=1; 
		}
		cout << ans << endl;
	}
	return 0;
}


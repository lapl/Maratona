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

long long aux[50000];

long long H(int n){
      long long res = 0;
      int end = sqrt(n);
     for( int i = 1; i <= end; i=i+1 ){
            res = (res + n/i);
            aux[i]=n/i;
      }
     return res;
}

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		scanf("%d",&n);
		if(n<=0) printf("0\n");
		else if(n == 1) printf("1\n");
		else {
			long long ans = H(n);
			//printf("before %lld\n",ans);
			int end = sqrt(n);
			for(int i = 1; i < end; ++i) {
				//printf("%lld %lld\n",aux[i],aux[i+1]);
				ans+=i*(aux[i]-aux[i+1]);
				//printf("%lld\n",ans);
			}
			for(int i = end; i < aux[end]; ++i) {
				ans+=i;
			}
			printf("%lld\n",ans);
		}
	}
}


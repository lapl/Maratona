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

 
int lis[10010], lds[10010], A[10010], B[10010], n;
int lisi[10010],ldsi[10010];

int main () {
    while(cin >> n) {
        REP(i,n) cin >> A[i];
        int i,z,w,ans=1;
        REP(i,n) B[i] = A[n-1-i];
        lis[0] = A[0];
        lds[0] = B[0];
        ZERO(lisi); ZERO(ldsi);
        lisi[0] = 1;
        ldsi[0] = 1;
        for(i = z = w =  1; i < n; ++i) {
            int x = lower_bound(lis,lis+z,A[i])-lis;
            int y = lower_bound(lds,lds+w,B[i])-lds;
            if(x == z) ++z;
            if(y == w) ++w;
            lis[x] = A[i];
            lds[y] = B[i];
            lisi[i] = x+1;
            ldsi[n-1-i] = y+1;
            
        }   
        REP(i,n) ans = max(ans,min(lisi[i],ldsi[i]));
        printf("%d\n", 2*ans - 1);
    }
    return 0;
}


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

int lol;

char buf[20010];
int n;
void foo(int i, int j) {
    int a = n-1;
   // cout << i << " " << j;
    int dist = abs(i-a)+abs(j-a);
    if(dist >= n) buf[lol++] = '.';
    else buf[lol++] = (dist%26)+'a';
}

int main () {
    int r1, c1, r2, c2;
    for(int cases = 1; cin >> n >> r1 >> c1 >> r2 >> c2; ++cases) {
        if(!n) break;
        int aux1, aux2;
        int mod = 2*n-1;
        printf("Case %d:\n",cases);
        for(int aux1 = r1, i = r1%mod; aux1 <= r2; i=(i+1)%mod,++aux1) {
               lol = 0;
               for(int aux2 = c1, j = c1%mod; aux2 <= c2; j = (j+1)%mod,++aux2) {
                    foo(i,j);
                }
               buf[lol] = '\0';
               cout << buf << endl;
        }
    }
    return 0;
}


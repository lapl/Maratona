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

int V[1010],W[1010],dp[1010][35];

int main () {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		FOR(i,1,n+1) scanf("%d %d",&V[i],&W[i]);
		int g;
		cin >> g;
		int ans = 0;
		while(g--) {
			int mw;
			cin >> mw;
			REP(i,n+1) dp[i][0] = 0;
			REP(i,mw+1) dp[0][i] = 0;

			FOR(id,1,n+1) FOR(w,1,mw+1) {
				if(W[id] > w) dp[id][w] = dp[id-1][w];
				else dp[id][w] = max(dp[id-1][w],V[id] + dp[id-1][w-W[id]]);
			}
			ans+=dp[n][mw];
		}
		cout << ans << "\n";
	}
	return 0;
}


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

int R[2][4];

int main () {
	int tc;
	cin >> tc;
	for(int cases = 1; tc--; ++cases) {
		
		REP(i,2) REP(j,4) scanf("%d",&R[i][j]);
		
		int max1 = max(R[0][0],R[1][0]);
        int min1 = min(R[0][2],R[1][2]);
        int max2 = max(R[0][1],R[1][1]);
        int min2 = min(R[0][3],R[1][3]);
		
		int x = 0;
		if(max1 < min1 && (max2 < min2)) {
			x = (min1-max1)*(min2-max2);
		}
		int y=0;
		REP(i,2) {
			y+=(R[i][2]-R[i][0])*(R[i][3]-R[i][1]);
		}
		y-=2*x;
		int z = 10000 - y - x;

		printf("Night %d: %d %d %d\n",cases,x,y,z);
	}
	return 0;
}


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

int A[1010],B[1010],C[2010];

int n1,n2,n3;

int memo[1010][1010];

int f(int i, int x, int y) {
	if(memo[x][y]!=-1) return memo[x][y];
	if(i==n3-1) return 1;
	int aux = 0;
	if(x < n1 && C[i]==A[x]) {
		aux|=f(i+1,x+1,y);
	}
	if(y < n2 && C[i]==B[y]) {
		aux|=f(i+1,x,y+1);		
	}
	return memo[x][y]=aux;
}

int main () {
	while(scanf("%d %d",&n1,&n2) && (n1|n2)) {
		REP(i,n1) scanf("%d",&A[i]);
		REP(i,n2) scanf("%d",&B[i]);
		n3 = n1+n2;
		REP(i,n3) scanf("%d",&C[i]);
		CLR(memo,-1);
		int ok = f(0,0,0);
		printf(ok ? "possible\n" : "not possible\n");
	}
	return 0;
}


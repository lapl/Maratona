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
#include <stack>

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
#define INF 10000000

int A[2][10010],l;
int ans;
void foo(int x, int y, bool b) {
	int end = (x*100)/l;
	int aux = 0,ct=0;
	while(A[b][y] && (aux != end)) {
		--A[b][y];
		++aux;
		++ct;
		
	}	
	for(int i = y-1; i > 0 && (aux!=end); ) {
		while(i && (!A[b][i] || (!A[b][y-i]))) --i;
		if(!i) break;
		if(i == (y-i) && (A[b][i] < 2)) { --i; continue; }
		ct+=2;
		--A[b][i]; --A[b][y-i];
		++aux;
	}
	if(aux == end && (ct < ans)) ans = ct;
}

int main () {
	int n,m;
	while(scanf("%d %d",&n,&m) && n) {
		scanf("%d",&l);
		int k;
		scanf("%d",&k);
		ZERO(A);
		REP(i,k) { int x; scanf("%d",&x); ++A[0][x]; ++A[1][x];}
		ans = INF;
		if((n*100)%l == 0) foo(n,m,0);
		if((m*100)%l == 0) foo(m,n,1);
		if(ans != INF ? printf("%d\n",ans) : printf("impossivel\n"));
		 
	}
	return 0;
}


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

typedef vector<LL> VI;
typedef pair<LL,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

int m;

int abs2(int a) {
	return (a > 0 ? a : -a);
}

bool cmp(int a, int b) {
	if(a%m != b%m) return a%m < b%m;
	else if(abs(a)%2 != abs(b)%2) {
		if(1 == abs(a)%2) return true;
		else return false;
	}
	else if(1 == abs(a)%2) return a > b;
	else return a < b;
}

int v1[10010];

int main () {
	int n;
	while(scanf("%d %d",&n,&m) && n) {
		REP(i,n) {
			int aux;
			scanf("%d",&aux);
			v1[i] = aux;
		}
		sort(v1,v1+n,cmp);
		cout << n << " " << m << "\n";
		REP(i,n) cout << v1[i] << "\n";
	}
	cout << "0 0\n";
	return 0; 
}


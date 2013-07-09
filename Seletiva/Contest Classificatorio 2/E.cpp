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

PII v[5010];

bool cmp(PII p1, PII p2) {
	if(p1.ST != p2.ST) return p1.ST < p2.ST;
	return p1.ND > p2.ND;
}

vector<PII> ans;

int main () {
	int p,s;
	for(int cases = 1; scanf("%d %d",&p,&s) && p;++cases) {
		
		REP(i,s) {
			int x,y;
			scanf("%d %d",&x,&y);
			v[i] = MP(x,y);
		}
		sort(v,v+s,cmp);
		ans.clear();
		ans.PB(v[0]);
		int aux = 0;
		FOR(i,1,s) {
			if(v[i].ST <= ans[aux].ND) { ans[aux].ND = max(ans[aux].ND,v[i].ND); }
			else {
				ans.PB(v[i]);
				++aux;
			}
		}
		printf("Teste %d\n",cases);
		FORE(it,ans) {
			printf("%d %d\n",it->ST,it->ND);
		}
		printf("\n");
	}
	return 0;
}


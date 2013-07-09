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

VI adjList[100010];
map<int,int> m;

bool mark[100010];
bool root[100010];
int aux;
bool isTree;
void dfs(int u) {
	if(mark[u]){ isTree = 0; return; }
	mark[u]=1;
	++aux;
	REP(i,SIZE(adjList[u])) {
		dfs(adjList[u][i]);
	}
}

int main() {
	bool end = 0;
	for(int cases = 1;!end;++cases) {
		bool ok = 1;
		m.clear();
		int qtd = 0;
		while(ok) {
			string s;
			getline(cin,s);
			if(s=="")continue;
			istringstream is(s);
			int u,v;
			while(is >> u >> v) {
				if(u == 0 && (v == 0)) {ok=0;break;} 
				if(u<0 && v<0){ok=0;end=1;break;}
				if(m.find(u) == m.end()) { m[u]=qtd;root[qtd]=1;mark[qtd]=0;adjList[qtd++].clear();}
				if(m.find(v) == m.end()) { m[v]=qtd;mark[qtd]=0;adjList[qtd++].clear();}
				root[m[v]]=0;
				adjList[m[u]].PB(m[v]);
			}
		}
		if(end) break;
		if(qtd==0) printf("Case %d is a tree.\n",cases);
		else {
			int rt = -1;
			REP(i,qtd) if(root[i])rt=i;
			if(rt==-1){printf("Case %d is not a tree.\n",cases);continue;}
			aux = 0;
			isTree = 1;
			dfs(rt);
			isTree&=(aux==qtd);
			if(isTree) printf("Case %d is a tree.\n",cases);
			else printf("Case %d is not a tree.\n",cases);
		}
	}
	return 0;
}


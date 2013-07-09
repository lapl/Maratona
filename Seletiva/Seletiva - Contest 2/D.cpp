#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)
#define INF 1000000000
#define MAX_V 110

using namespace std;

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(int v, int minEdge) {
	if(v==s) { f = minEdge; return; }
	else if(p[v] != -1) {
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

void maxF () {
		mf = 0;
	while(1) {
		f = 0;
		vi dist(MAX_V,INF); dist[s] = 0;
		queue<int> q; q.push(s);
		p.assign(MAX_V,-1);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if(u == t) break;
			for(int v = 0; v < MAX_V; ++v)
				if(res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u] +1,q.push(v),p[v]=u;
		}
		augment(t,INF);
		if(f == 0) break;
		mf += f;
	}
}

int main () {
	int n;
	for(int cases = 1; scanf("%d",&n) && n; ++cases) {
		int c;
		scanf("%d %d %d",&s,&t,&c);
		--s; --t;
		memset(res,0,sizeof res);
		REP(i,c) {
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			--x; --y;
			res[x][y] += z;
			res[y][x] += z;
		}
		maxF();
		printf("Network %d\n", cases);
		printf("The bandwidth is %d.\n\n", mf);
	}
	return 0;
}


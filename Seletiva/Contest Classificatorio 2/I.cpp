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
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define INF 100000000


VI adjList[110010];
typedef pair<int,PII> PIII;
map<int,int> dist;
int parent[110010];
int s;
int n,m;

void printPath(int u) {
	if(u == s) { printf("%d",u+1); return; }
	printPath(parent[u]);
	if(u < m) printf(" %d",u+1);
}

int main () {
	scanf("%d %d",&n,&m);
	REP(i,n) {
		int k;
		scanf("%d",&k);
		int x;
		REP(j,k) {
			scanf("%d",&x);
			adjList[m+i].PB(x-1);
			adjList[x-1].PB(m+i);
		}
	}
	int end;
	scanf("%d %d",&s,&end);
	--s; --end;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		REP(j,SIZE(adjList[u])) {
			int v = adjList[u][j];
			if(dist.find(v) == dist.end()) {
				if(v < m) dist[v] = dist[u] + 1;
				else dist[v]=dist[u];
				parent[v]=u;
				q.push(v);
				if(v == end) {
					printf("%d\n",dist[v]);
					printPath(v);
					printf("\n");
					goto lol;
				}
			}
		}
	}
	printf("-1\n");
	lol:;
	return 0;
}


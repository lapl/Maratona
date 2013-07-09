#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <queue>
#define INF 1000000000
using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);i++)
#define SIZE(a) ((int)((a).size()))

struct Node {
	int v;
	int cost;
	int i;
	Node() {}
	Node(int _v, int _cost, int _i) : v(_v), cost(_cost), i(_i) {}
};

typedef pair<int,PII> PIII;
typedef vector<PIII> VIII;
vector<Node> adjList[4010];
char o[55],d[55],a[55],b[55],w[55];
map<string,int> parse;

int dist[4010][27];

int main () {
	int m;
	while(scanf("%d",&m) && m) {
		REP(i,2*m+5) adjList[i].clear();
		parse.clear();
		scanf("%s %s",o,d);
		parse[o] = 0; parse[d] = 1;
		int qtd = 2;		
		REP(i,m) {
			scanf("%s %s %s",a,b,w);
			int cost = (int)strlen(w);
			if(parse.find(a) == parse.end()) parse[a] = qtd++;
			if(parse.find(b) == parse.end()) parse[b] = qtd++;
			int pa = parse[a], pb = parse[b];
			adjList[pa].PB(Node(pb,cost,w[0]-'a'));
			adjList[pb].PB(Node(pa,cost,w[0]-'a'));
		}
		priority_queue<PIII, VIII,greater<PIII> > pq;
		pq.push(MP(0,PII(0,26)));
		
		REP(i,2*m+5) REP(j,27) dist[i][j] = INF;
		dist[0][26] = 0;
		
		while(!pq.empty()) {
			PIII front = pq.top(); pq.pop();
			int d = front.ST, u = front.ND.ST; int ini = front.ND.ND;
			if(d == dist[u][ini]) {
				REP(j,SIZE(adjList[u])) {
					Node v = adjList[u][j];
					if(v.i == ini) continue;
					if(dist[u][ini] + v.cost < dist[v.v][v.i]) {
						dist[v.v][v.i] = dist[u][ini] + v.cost;
						pq.push(MP(dist[v.v][v.i],PII(v.v,v.i)));
					}
				}
			}
		}
		int res = INF;
		REP(i,27) res = min(res, dist[1][i]);
		if(res != INF) printf("%d\n",res);
		else printf("impossivel\n");
	}
}


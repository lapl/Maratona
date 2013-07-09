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
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

typedef pair<int,double> PID;
typedef vector<PID> VID;

struct Node {
	int x,y;
	int size;
	VID prob;
} tree[650];

double Prob[310][310];

int sizeNode (int n) {
	if(tree[n].size != 0) return tree[n].size;
	int x = tree[n].x, y = tree[n].y;
	if(tree[x].size != 0) tree[x].size;
	else {
		tree[x].size = sizeNode(x);
	}
	if(tree[y].size != 0) tree[y].size;
	else {
		tree[y].size = sizeNode(y);
	}
	return tree[x].size + tree[y].size;
}

int N;
void calcProb (int n) {
	Node* x = &tree[tree[n].x];
	Node* y = &tree[tree[n].y];
	if(n <= N) return;
	calcProb(tree[n].x);
	calcProb(tree[n].y);
	FORE(i,x->prob) {
		double aux = 0.0;
		FORE(j,y->prob) {
			aux+=(j->ND*Prob[i->ST][j->ST]);
		}
		tree[n].prob.PB(MP(i->ST,i->ND*aux));
	}
	FORE(i,y->prob) {
		double aux = 0.0;
		FORE(j,x->prob) {
			aux+=(j->ND*Prob[i->ST][j->ST]);
		}
		tree[n].prob.PB(MP(i->ST,i->ND*aux));
	}
}

int main () {
	while(scanf("%d",&N) && N) {
		FOR(i,1,N) FOR(j,1,N) {
			scanf("%lf",&Prob[i][j]);
		}
		int start = N+1, end = 2*N-1;
		FOR(i,1,N) {
			tree[i].prob.clear();
			tree[i].prob.PB(MP(i,1.0));
			tree[i].size = 1;
		}
		FOR(i,start,end) {
			tree[i].prob.clear();
			tree[i].size = 0;
			scanf("%d %d",&tree[i].x,&tree[i].y);
		}
		int root = -1;
		FOR(i,start,end) {
			if(sizeNode(i) == N) root = i;
			//cout << sizeNode(i) << endl;
		}
		calcProb(root);
		double ans = 0;
		FORE(it,tree[root].prob) {
			if(it->ST == 1) ans = it->ND;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}


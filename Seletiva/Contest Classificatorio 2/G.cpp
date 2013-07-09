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

int grid[22][22];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int m,n;
bool valid(int x, int y) {
	return (x >= 0 && x < m && y >= 0 && y < n);
}


typedef pair<int,PII> PIII;

map<PIII,int> dist;

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d %d",&m,&n);
		int k;
		scanf("%d",&k);
		REP(i,m) REP(j,n) scanf("%d",&grid[i][j]);
		
		queue<PIII> q;
		q.push(MP(0,MP(0,0)));
		dist.clear();
		dist[MP(0,MP(0,0))]=0;
		bool ok = 1;
		while(ok && !q.empty()) {
			PIII front = q.front(); q.pop();
			int xa = front.ND.ST;
			int ya = front.ND.ND;
			int ka = front.ST;
			REP(j,4) {
				int tx = xa + dx[j];
				int ty = ya + dy[j];
				if(valid(tx,ty)) {
					if(grid[tx][ty]==0) {
						if((tx == (m - 1))&&(ty==(n-1))) {
							printf("%d\n",dist[front] + 1);
							ok=0;
							break;	
						} else {
							PIII aux = MP(0,MP(tx,ty));
							if(dist.find(aux) == dist.end()) {
								dist[aux] = dist[front] + 1;
								q.push(aux);
							}
						}
					} else {
						if(ka == k) continue;
						PIII aux = MP(ka+1,MP(tx,ty));
						if(dist.find(aux) == dist.end()) {
								dist[aux] = dist[front] + 1;
								q.push(aux);
						}
					}
				}
			}
		}
		if(m == 1 && (n == 1)) printf("%d\n",0);
		else if(ok) printf("-1\n");
	}
	return 0;
}


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

map<int,int> M[3];
map<int,int> M2[3];

int grid[35][35][35];

vector<int> A[3];

int para[20][6];

int main () {
	int n;
	while(scanf("%d",&n) == 1) {
		REP(i,3) { M[i].clear(); M[i].insert(MP(0,0)); M2[i].clear(); M2[i].insert(MP(0,0));}
		REP(i,3) { A[i].clear(); A[i].PB(0);}
		REP(j,n) {
			REP(i,6) {
				int x;
				scanf("%d",&x);
				para[j][i] = x;
				A[i%3].PB(x);
			}
		}
		REP(i,3) sort(ALL(A[i]));
		
		REP(i,3) {
			int aux = 1;
			REP(j,SIZE(A[i])) {
				if(M[i].find(A[i][j]) == M[i].end()) {
					M[i].insert(MP(A[i][j],aux));
					M2[i].insert(MP(aux++,A[i][j]));
				}
			}
		}
		/*REP(i,3) {
			cout << "eixo: " << i << endl;
			FORE(it,M[i]) {
				cout << it->ST << " " << it->ND << endl;
			}
		}*/
		ZERO(grid);
		REP(i,n) {
			int startX = M[0][para[i][0]], endX = M[0][para[i][3]];
			int startY = M[1][para[i][1]], endY = M[1][para[i][4]];
			int startZ = M[2][para[i][2]], endZ = M[2][para[i][5]];
			//printf("i %d j %d  ",i,j);
			//printf("%d %d\n",startX,endX);
			FOR(x, startX, endX+1)
				FOR(y, startY, endY+1)
					FOR(z, startZ, endZ+1) {
						++grid[x][y][z];
						//printf("%d %d %d\n",x,y,z);
					}
						
		}
		int ans = 0;
		FOR(i,0,30) FOR(j,0,30) FOR(k,0,30) {
			if (grid[i][j][k] >1 && grid[i+1][j][k]>1 && grid[i][j+1][k]>1 && grid[i][j][k+1]>1 && grid[i+1][j+1][k]>1 && grid[i+1][j][k+1]>1 && grid[i][j+1][k+1] >1&& grid[i+1][j+1][k+1]>1){
				ans+=((M2[0][i+1]-M2[0][i])*(M2[1][j+1]-M2[1][j])*(M2[2][k+1]-M2[2][k]));
			}
		} 
		cout << ans << endl;
	}
	return 0;
}


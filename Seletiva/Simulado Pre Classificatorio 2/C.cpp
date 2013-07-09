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
 
int kx[] = {2,1,-1,-2,-2,-1,1,2};
int ky[] = {1,2,2,1,-1,-2,-2,-1};
int qx[] = {1,1,0,-1,-1,-1,0,1};
int qy[] = {0,1,1,1,0,-1,-1,-1};
 
int n,m;
 
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m; 
}
 
int tab[1010][1010];
PII queens[110];
 
int main () {
        for(int cases = 1; scanf("%d %d",&n,&m) && (n|m); ++cases) {
                n; m; int q;
                ZERO(tab);
                for(int k = 1; k <= 3; ++k) {
                        int qtd;
                        scanf("%d",&qtd);
                        if(k == 1) q = qtd;
                        for(int i = 0; i < qtd; ++i) {
                                int x,y;
                                scanf("%d %d",&x,&y);
                                --x; --y;
                                tab[x][y] = k;
                                if(k == 1) {
                                        queens[i] = PII(x,y);
                                } else if(k == 2) {
                                        for(int id = 0; id < 8; ++id) {
                                                int tx = x + kx[id];
                                                int ty = y + ky[id];
                                                if(valid(tx,ty) && (tab[tx][ty] == 0)) {
                                                        tab[tx][ty] = 4;
                                                }
                                        }
                                }
                        }
                }
                        for(int i = 0; i < q; ++i) {
                                int x = queens[i].ST, y = queens[i].ND;
                                for(int id = 0; id < 8; ++id) {
                                        int tx = x, ty = y;
                                        while(1) {
                                                tx = tx+qx[id];
                                                ty = ty+qy[id];
                                                if(valid(tx,ty) && (tab[tx][ty] == 4 || tab[tx][ty] == 0))
                                                        tab[tx][ty] = 4;
                                                else break;
                                        }
                                }
                        }
                        int resp = 0;
                        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
                                if(tab[i][j] == 0) ++resp;
                        }
                        cout << "Board " << cases << " has " << resp << " safe squares." << endl;
                }
        return 0;
}


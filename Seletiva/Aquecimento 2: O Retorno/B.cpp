#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define NOTLETTER(ch) ((ch < 'a' || ch > 'z')) && (ch < 'A' || ch > 'Z')
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

int peca(int x, int y) {
	return (15-x)*x/2 + y - x + 1;
}

bool used[30];
bool used2[7][8];
int tab[7][8];
int sol;

void backtrack(int x, int y) {
	while(used2[x][y] && x < 7) {
		if(y < 7) {
			++y;
		} else {
			y = 0;
			++x;
			if(x == 7) break;
		}
	}
	if(x == 7) { ++sol; return; }
	int tx = min(tab[x][y],tab[x][y+1]);
	int ty = max(tab[x][y],tab[x][y+1]);
	if(!used[peca(tx,ty)]) {
			if((y + 1) < 8 && (!used2[x][y+1])) { 
			used2[x][y] = 1;
			used2[x][y+1] = 1;
			used[peca(tx,ty)] = 1;
			backtrack(x,y);
			used2[x][y] = 0;
			used2[x][y+1] = 0;
			used[peca(tx,ty)] = 0;
		}
	}
	tx = min(tab[x][y],tab[x+1][y]);
	ty = max(tab[x][y],tab[x+1][y]);
	if(!used[peca(tx,ty)]) {
		if((x + 1) < 7 && (!used2[x+1][y])) {
			used2[x][y] = 1;
			used2[x+1][y] = 1;
			used[peca(tx,ty)] = 1;
			backtrack(x,y);
			used2[x][y] = 0;
			used2[x+1][y] = 0;
			used[peca(tx,ty)] = 0;
		}
	}
}

int main () {
	int tc;
	scanf("%d",&tc);
	for(int teste = 1; tc--; ++teste) {
		FOR(i,7) FOR(j,8) scanf("%d",&tab[i][j]);
		sol = 0;
		memset(used,0,sizeof used);
		memset(used2,0,sizeof used2);
		backtrack(0,0);
		printf("Teste %d\n%d\n\n", teste,sol);
	}
	return 0;
}


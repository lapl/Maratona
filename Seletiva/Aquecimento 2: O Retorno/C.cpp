//TEMPLATE

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

int V[55],W[55],memo[55][1010];
int c,f;
int value(int id, int w) {
	if(w == 0) return 0;
	if(id == f) return 0;
	if(memo[id][w] != -1) return memo[id][w];
	if(W[id] > w) return memo[id][w] = value(id+1,w);
	return memo[id][w] = max(value(id+1,w),V[id] + value(id+1,w - W[id]));
}

int main () {
	for(int teste = 1; scanf("%d %d",&c,&f) && c&&f; ++teste) {
		FOR(i,f) {
			scanf("%d %d",&W[i],&V[i]);
		}
		memset(memo,-1,sizeof memo);
		printf("Teste %d\n", teste);
		printf("%d\n\n", value(0,c));
	}
	return 0;
}


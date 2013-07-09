#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define mp make_pair
#define pb push_back
#define ALL(c) (c.begin(),c.end())

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

int main () {
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF) {
		int x = 0;
		int y = 0;
		while(n > 0) {
			if(k <= n){
				x+=(k*(n/k));
				y = n/k;
				n%=k;
				n+=y;
			} else {
				x+=n;
				break;
			}
		}
		printf("%d\n", x);
	}
	return 0;
}


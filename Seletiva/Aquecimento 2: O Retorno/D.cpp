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

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		int ans = -1000000;
		int temp = 0;
		FOR(i,n) {
			int x;
			scanf("%d",&x);
			temp+=x;
			ans=max(ans,temp);
			if(temp < 0) temp = 0;
		}
		printf("%d\n", ans);
	}
	return 0;

}


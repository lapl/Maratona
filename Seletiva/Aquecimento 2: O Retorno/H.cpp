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
	long long n;
	while(scanf("%lld",&n) && n)
	 {
		long long x = (long long)ceil(sqrt(n));
		if (n == x*x) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


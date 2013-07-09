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
#define ALL(c) (c.begin(),c.end())

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

ll fib[52];


ll calc (int n) 
{
	if(n == 0) return 1;
	if(n == 1) return 2;
	if(fib[n] != -1) return fib[n];
	return fib[n] = calc(n-1) + calc(n-2);
}

int main () 
{
	int tc;
	scanf("%d",&tc);
	int n;
	memset(fib,-1,sizeof fib);
	for(int cases = 1; tc--; ++cases) {
		printf("Scenario #%d:\n",cases);
		scanf("%d",&n);
		printf("%lld\n\n", calc(n));
	}
	return 0;
}


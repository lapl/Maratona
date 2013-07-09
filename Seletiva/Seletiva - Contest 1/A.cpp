#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,(a))
#define LSOne(S) (S & (-S))
#define INF 1e9
#define EPS 1e-7
using namespace std;

typedef long long LL;

LL coins [1010];

int main () {
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		int ans = 1;
		LL last = 0;
		REP(i,n) {
			cin >> coins[i];
		}
		REP(i,n-1) {
			if(last+coins[i] < coins[i+1]) {
				++ans;
				last += coins[i];
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}


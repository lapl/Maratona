#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,(a))

using namespace std;

typedef vector<int> vi;

int main () {
	int tc;
	cin >> tc;
	while(tc--) {
		vi v;
		int x;
		while(cin >> x && x) {
			v.push_back(x);
		}
		sort(v.begin(),v.end(),greater<int>());
		int ans=0;
		bool ok = 1;
		REP(i,v.size()) {
			ans+= (2*pow(v[i],i+1));
			if(ans > 5000000) { ok=0;break; }
		}
		if(ok) printf("%d\n", ans);
		else printf("Too expensive\n");
	}
	return 0;
}


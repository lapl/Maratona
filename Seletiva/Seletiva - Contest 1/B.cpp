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
	int a,c;
	while(scanf("%d %d",&a,&c) && a) {
		int ans = 0;
		int last = a;
		REP(i,c) {
			int x;
			scanf("%d",&x);
			if(x < last) {
				ans+=(last-x);
			}
			last = x;
		}
		printf("%d\n", ans);
	}
	return 0;
}


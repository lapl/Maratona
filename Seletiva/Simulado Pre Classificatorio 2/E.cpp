#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <map>
#include <cmath>
#define isLetter(ch) (((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z'))
using namespace std;

#define ST first
#define ND second
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FORED(a,b) for(VAR(a,(b).rbegin());a!=(b).rend();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(a) ((int)((a).size()))
char line[1024];
typedef vector<int> VI;
typedef pair<int,int> PII;

int main () {
	string line;
	while(cin >> line) {
		if(line == "0") break;
		int ans = 0;
		FORD(i,SIZE(line),1) {
			ans+=((line[SIZE(line)-i]-'0')*(pow(2,i)-1));
		}
		printf("%d\n", ans);
	}
	return 0;
}


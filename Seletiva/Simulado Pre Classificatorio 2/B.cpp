#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <map>
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
char line[1024];
typedef vector<int> VI;
typedef pair<int,int> PII;

bool cmp(PII p1, PII p2) {
	if(p1.ST != p2.ST) return p1.ST > p2.ST;
	return p1.ND < p2.ND;
}

int main () {
	map<char,int> m;
	vector<PII> v;
	int n;
	scanf("%d\n",&n);
	while(n--) {
		gets(line);
		int len = (int)strlen(line);
		REP(i,len) {if(isLetter(line[i])) ++m[toupper(line[i])];}
	}
	FORE(it,m) v.PB(PII(it->ND, it->ST));
		sort(ALL(v),cmp);
		FORE(it, v) {
			printf("%c %d\n", it->ND, it->ST);
		}
	return 0;
}


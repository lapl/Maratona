//TEMPLATE

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define NOTLETTER(ch) ((ch < 'a' || ch > 'z')) && (ch < 'A' || ch > 'Z')
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

char line[1024];

bool read () {
	if(gets(line) == NULL) return false;
	return true;
}

void process() {
	int len = strlen(line);
	bool k = 0;
	int words = 0;
	FOR(i,len) {
		if(NOTLETTER(line[i])) {
			if(k == 1) ++words;
			k = 0;
		} else {
			k = 1;
		}
	}
	printf("%d\n",words);
}

int main () {
	while(read()) process();
	return 0;
}


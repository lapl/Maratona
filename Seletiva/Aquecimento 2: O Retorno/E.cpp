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

bool aux[1010];

char line[1024];

int main () {
	int pages;
	while(scanf("%d\n",&pages) && pages) {
		gets(line);
		int len = strlen(line);
		int begin= -1,end = -1;
		bool k = 0;
		int i = 0;
		memset(aux,0,sizeof aux);
		while(i < len) {
			int x;
			sscanf(line+i,"%d",&x);
			++i;
			if(x >= 10) ++i;
			if(x >= 100) ++i;
			if(x >= 1000) ++i;
			if(begin == -1) begin = x;
			else end = x;
			if(line[i] == '-') { 
				++i; continue;
			}
			else {
				if(begin > end && (end != -1)) { ++i; begin = end = -1; continue;}
				if(end > pages) end = pages;
				if(end == -1) end = begin;
				//printf("%d %d\n", begin,end);
				for(int j = begin; j <= end; ++j) {
					aux[j-1] = 1;
				}
				++i; begin = end = -1;
			}
		}
		int ans = 0;
		FOR(i,pages) {
			if(aux[i]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}


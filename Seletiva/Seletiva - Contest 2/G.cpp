#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

int A[11];
char line[1010];

using namespace std;

int main () {
	int tc;
	cin >> tc;
	while(tc--) {
		memset(A,0,sizeof A);
		scanf("%s",line);
		int len = strlen(line);
		int aux = 1;
		int atual = line[0]-'0';
		FOR(i,1,len) {
			if(line[i]-'0' != atual) {
				printf("%d%d", aux,atual);
				atual = line[i]-'0';
				aux = 0;
			}
			++aux;
		}
		printf("%d%d", aux,atual);
		printf("\n");
	}
	return 0;
}


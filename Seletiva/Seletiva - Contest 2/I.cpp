#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

using namespace std;

bool isPal(int num, int n) {
	ostringstream os1;
	os1 << num;
	string s = os1.str();
	int size = s.size();
	ostringstream os;
	while(size != n) {
		os<<'0';
		++size;
	}
	os << num;
	s = os.str();
	REP(i,n) {
		if(s[i]!=s[n-1-i]) return false;
	}
	return true;
}


char line[12];
int l[12];

int main () {
	/*while(scanf("%s",line)) {
		if(strcmp(line,"0") == 0) break;
		int len = strlen(line);
		REP(i,len) l[i] = line[i]-'0';
		REP(i,len) {
			if(l[i] == l[len-i-1]) continue;
			else if(l[i] < l[len-i-1]) {
				int aux = 10-l[len-i-1] + l[i] - 0;
				sum+=(aux)*(pow(10,i)));
				l[len-i-1] = l[i];
				if(line[len-i-2] == '9') {}
			}
 		}
	}*/
 	int n;
 	while(scanf("%s",line)) {
 		sscanf(line,"%d",&n);
 		if(strcmp(line,"0") == 0) break;
 		int size = strlen(line);
 		int aux = n;
 		while(1) {
 			if(isPal(aux,size)) break;
 			++aux;
 		}
 		printf("%d\n", aux - n);
 	}
 	return 0;
}


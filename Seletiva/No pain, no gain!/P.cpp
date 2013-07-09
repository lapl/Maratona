#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>
#include <stack>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

char line[20];

int main () {
	int tc;
	fgets(line, sizeof(line), stdin);
	sscanf(line,"%d",&tc);
	fgets(line, sizeof(line),stdin);
	while(tc--) {
		stack<char> s;
		while(1) {
			if(!fgets(line,sizeof(line),stdin)) break;
			if(line[0] == '\n') break;
			char c = line[0];
			if(isdigit(c)) printf("%c",c);
			else {
				if(c == ')') {
					while(1) {
						char front = s.top(); s.pop();
						if(front == '(') break;
						printf("%c",front);
					}
				}
				else {
					if(c == '(') { s.push(c); continue; }
					if(s.empty()) s.push(c);
					else {
						while(!s.empty()) {
							char front = s.top();
							if((c == '*' || c == '/') && (front != '*' && front != '/')) {
								s.push(c); break;
							} else if (front == '(') {
								s.push(c); break;
							} else {
								printf("%c",front);
								s.pop();
							}
						}
						if(s.empty()) s.push(c);
					}	
				}
			}
		}
		while(!s.empty()) {
			char front = s.top(); s.pop();
			printf("%c",front);
		}
		printf("\n");
		if(tc) printf("\n");
	}
	return 0;
}


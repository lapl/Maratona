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
#define INF 1000000000
using namespace std;

typedef vector<int> vi;

int old[110][110];
int nova[110][110];

int main () {
	int n;
	while(scanf("%d\n",&n) && n) {
		REP(i,n) REP(j,n) old[i][j] = INF;
		REP(i,n) REP(j,n) nova[i][j] = INF;
		REP(i,n) old[i][i]=0;
		REP(i,n) nova[i][i]=0;
		REP(i,n) {
			string s;
			getline(cin,s);
			istringstream is(s);
			int x,y;
			is >> x;
			--x;
			while(is >> y) {
				--y;
				old[x][y] = 1;
			}
		}
		REP(k,n) REP(i,n) REP(j,n) {
			old[i][j] = min(old[i][j],old[i][k]+old[k][j]);
		}
		REP(i,n) {
			string s;
			getline(cin,s);
			istringstream is(s);
			int x,y;
			is >> x;
			--x;
			while(is >> y) {
				--y;
				nova[x][y] = 1;
			}
		}
		REP(k,n) REP(i,n) REP(j,n) {
			nova[i][j] = min(nova[i][j],nova[i][k]+nova[k][j]);
		}
		int A,B;
		scanf("%d %d",&A,&B);
		bool ok = 1;
		REP(i,n) REP(j,n) {
			ok&=(nova[i][j] <= (A*old[i][j]+B));
		}
		printf(ok ? "Yes\n" : "No\n");
	}
	return 0;
}


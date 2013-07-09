#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

pair<double,double> pos[20];

double dist[20][20], memo[1<<17];

char lol[25];

int N, all;

double solve(int mask) {
	if(memo[mask] > -0.5) return memo[mask];
	if(mask == all-1) {
		return memo[mask] = 0;
	}

	double ans = 1e100;
	for (int i = 0; i < N; ++i) {
		if(!(mask & (1<<i))) {
			for(int j = i+1; j < N; ++j) {
				if(!(mask & (1<<j))) {
					ans = min(ans,dist[i][j] + solve(mask | (1<<i) | (1<<j)));
				}
			}
		}
	}
	return memo[mask] = ans;
}

int main () {
	int n;
	for (int cases = 1; scanf("%d",&n) && n; ++cases) {
		N = 2*n;
		all = 1<<N;
		for(int i = 0; i < N; ++i) {
			scanf("%s %lf %lf", lol, &pos[i].first, &pos[i].second);
		}
		for (int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				dist[i][j] = hypot(pos[i].first - pos[j].first, pos[i].second - pos[j].second);
			}
		}
		memset(memo,-1,sizeof memo);
		printf("Case %d: %.2lf\n", cases, solve(0));
	}
}


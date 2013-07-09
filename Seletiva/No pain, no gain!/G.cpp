//TODO passar para Segment Tree

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

using namespace std;

#define LSOne(S) (S & (-S))
#define SIZE(v) (int)(v).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i = (a);i<(b);++i)

int ft[200010];
int pot[200010];
char line[10];
int n;
void ft_create(int n) {
	REP(i,n+1) ft[i]=0;
}

int ft_rsq(int b) {
	int sum = 0;
	for(;b;b-=LSOne(b)) sum+=ft[b];
	return sum;
}

int ft_rsq(int a, int b) {
	return ft_rsq(b) - (a == 1 ? 0 : ft_rsq(a-1));
}

void ft_adjust(int k, int v) {
	for(; k < n+1; k += LSOne(k)) {
		ft[k] += v;
	}
}

int main () {
	for(int cases = 1; scanf("%d",&n) && n; ++cases) {
		if(cases!=1) printf("\n");
		printf("Case %d:\n",cases);
		int x,y;
		ft_create(n);
		FOR(i,1,n+1) {
			scanf("%d",&x);
			pot[i]=x;
			ft_adjust(i,x);
		}
		while(1) {
			scanf("%s",line);
			if(strcmp(line,"END") == 0) break;
			scanf("%d %d",&x,&y);
			if(line[0] == 'M') {
				printf("%d\n",ft_rsq(x,y));
			} else {
				ft_adjust(x,-pot[x]);
				pot[x]=y;
				ft_adjust(x,y);
			}
		}
	}
	return 0;
}


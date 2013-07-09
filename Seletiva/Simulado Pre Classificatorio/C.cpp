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
#define ALL(c) (c.begin(),c.end())

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

int arr[55],memo[55][55];

int cut(int left, int right) {
	if(left + 1 == right) return 0;
	if(memo[left][right] != -1) return memo[left][right];
	int menor = 100000;
	for(int i = left + 1; i <= (right -1);++i) {
		menor = min(menor,cut(left,i)+cut(i,right) + arr[right] - arr[left]);
	}
	return memo[left][right] = menor;
}

int main () {
	ll x,y;
	int l,cuts;
	while(scanf("%d",&l) && l) {
		scanf("%d",&cuts);
		memset(memo,-1,sizeof memo);
		arr[0] = 0;
		arr[cuts+1] = l;
		REP(i,1,cuts+1) scanf("%d",&arr[i]);
		printf("The minimum cutting is %d.\n",cut(0,cuts+1));
	}
	return 0;
}


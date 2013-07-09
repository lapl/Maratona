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

int A[1111];

int main () {
	int n;
	while(scanf("%d",&n) != EOF) {
		FOR(i,n) scanf("%d",&A[i]);
		int inversions = 0;
		FOR(i,n)FOR(j,n-1) {
			if(A[j+1] < A[j]) {
				swap(A[j],A[j+1]);
				++inversions;
			}
		}
		printf("Minimum exchange operations : %d\n", inversions);
	}
	return 0;
}


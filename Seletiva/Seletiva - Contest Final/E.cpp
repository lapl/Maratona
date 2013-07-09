#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;

int A[25];

int main () {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		REP(i,n) scanf("%d",&A[i]);
		sort(A,A+n);
		int end = A[n-1];
		int sum=0;
		for(int i = 0; i < (n-1); ++i) {
			sum+=(A[i+1]-A[i]);
		}		
		sum+=(A[n-1]-A[0]);
		printf("%d\n", sum);
	}
	return 0;
}


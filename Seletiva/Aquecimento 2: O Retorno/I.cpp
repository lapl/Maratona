#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define NOTLETTER(ch) ((ch < 'a' || ch > 'z')) && (ch < 'A' || ch > 'Z')
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;

int A[1000010],B[1000010];

ll mergesort(int begin, int end) {
	if(begin == end) return 0;

	ll inv_index = 0;
	int middle = (begin+end)/2;
	inv_index+=mergesort(begin,middle);
	inv_index += mergesort(middle+1,end);

	int left = begin;
	int right = middle+1;
	for(int k = begin; k <= end; ++k) {
		if(right > end || (left <= middle && (A[left] <= A[right]))) {
			B[k] = A[left++];
		} else {
			B[k] = A[right++];
			inv_index+=(middle - left +1);
		}
	}
	for(int k = begin; k <= end; ++k) A[k] = B[k];
	return inv_index;
}

int main () {
	int n;
	while(scanf("%d",&n) != EOF) {
		FOR(i,n) scanf("%d",&A[i]);
		printf("%lld\n", mergesort(0,n-1));
	}
	return 0;
}


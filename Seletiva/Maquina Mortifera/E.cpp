#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;


int main () { 
	int tc;
	scanf("%d",&tc);
	for(int cases = 1; tc--;++cases) {
		int n;
		scanf("%d",&n);
		vector<int> v;
		bool first = 1;
		printf("Case %d: ",cases);
		for(int x = sqrt(n)-1; x > 0;--x) {
			int i = n-x*x;
			if(i%x==0) first ? printf("%d",i),first=0 : printf(" %d",i);
		}
		printf("\n");
	}
	return 0;
}


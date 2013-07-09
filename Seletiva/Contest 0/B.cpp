#include <cstdio>

int main () {
	int TC;
	scanf("%d",&TC);
	for (int cases = 1; TC--; ++cases) {
		int a,b;
		scanf("%d %d",&a,&b);
		int sum = 0;
		for(int i = a; i <= b; ++i) {
			if ((i % 2) == 1) sum+=i;
		}
		printf("Case %d: %d\n",cases,sum);
	}
	return 0;
}

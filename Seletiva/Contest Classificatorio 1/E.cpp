#include <cstdio>

typedef long long ll;
int dp[15];

int main () {
	dp[0] = 1;
	for(int i = 0; i <= 10; ++i) {dp[i+1] = dp[i]*((2*i+2)*(2*i+1))/
											((i+2)*(i+1));
	}
	int n;
	bool first = 1;
	while(scanf("%d",&n) != EOF) {
		first ? first = 0: printf("\n");
		printf("%d\n", dp[n]);
	}
	return 0;
}

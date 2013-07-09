#include <cstdio>
#include <cstring>
int F[111];

int f(int n) {
	if (n == 1) return 1;
	if (F[n] != -1) return F[n];
	return F[n] = n*n +f(n-1);
}

int main () {
	int N;
	memset(F,-1,sizeof F);
	while(scanf("%d\n",&N) && N) {
		printf("%d\n",f(N));
	}
	return 0;
}


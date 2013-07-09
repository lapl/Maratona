#include <cstdio>


char pais[100000];
int main () {
	int T,N;
	while(scanf("%d %d",&T,&N) && T) {
		int points = 0;
		int x;
		while(T--) {
			scanf("%s %d",pais,&x);
			points+=x;
		}
		printf("%d\n",N*3 - points);
	}
	return 0;
}


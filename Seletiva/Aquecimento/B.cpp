#include <cstdio>

int main () {
	int N;
	while(scanf("%d",&N) && N) {
		int rect,aux=0,c,qtd;
		while(N--) {
			scanf("%d %d",&c,&qtd);
			aux+=(qtd/2);
		}
		rect = aux/2;
		printf("%d\n", rect);
	}
	return 0;
}


#include <cstdio>

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		int aux;
		scanf("%d",&aux);
		for(int i = 1; i < n; ++i) {
			int x; scanf("%d",&x);
			aux^=x;
		}
		printf(aux == 0 ? "No\n" : "Yes\n");
	}
	return 0;
}


#include <cstdio>
#define VALID(x,y,n,m) (x >= 0 && (x < n) && (y >= 0) && (y<m))
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,1,-1,-1,0,1};

char table[111][111];

int main () {
	int n,m;
	bool first = 1;
	for (int f = 1; scanf("%d %d\n",&n,&m) && n;++f) {
		first ? first = 0 : printf("\n");
		printf("Field #%d:\n", f);
		for(int i = 0; i < n; ++i) {
			scanf("%s",table[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (table[i][j] == '*') {
					printf("*");
					continue;
				}
				int count = 0;
				for (int aux = 0; aux < 8; ++aux) {
					int tx = (i+dx[aux]),ty = (j+dy[aux]);
					if(VALID(tx,ty,n,m)) {
						if(table[tx][ty] == '*') {
							++count;
						}
					}
				}
				printf("%d", count);
			}
			printf("\n");
		}
	}
	return 0;
}


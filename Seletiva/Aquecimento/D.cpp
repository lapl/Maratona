#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

bool diff[3010];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(diff,0,sizeof diff);
		int x,y,aux = 1;
		bool j = 1;
		scanf("%d",&x);
		for (int i = 1; i < n;++i) {
			scanf("%d",&y);
			diff[(int)abs(x-y)] = 1;
			x = y;
		}
		for (int i = 1; i < n; ++i) {
			if (!diff[i]) j = 0;
		}
		printf(j ? "Jolly\n" : "Not jolly\n");
	}
	return 0;
}


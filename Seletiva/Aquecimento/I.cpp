#include <cstdio>
#include <cstring>
int mary[111];
int john[111];
int main () {
	int N,x,mp,mi,jp,ji;
	while(scanf("%d",&N) && N) {
		mp = mi = jp = ji = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%d",&mary[i]);
		}
		for(int i = 0; i < N; ++i) {
			scanf("%d",&john[i]);
		}
		int impar = 0;
		for (int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if((mary[i]!=-1)&&(john[j]!=-1)&& (mary[i] + john[j])%2==1) {++impar;mary[i] = -1;john[j] = -1;}

		printf("%d\n", N-impar);

	}
	return 0;
}


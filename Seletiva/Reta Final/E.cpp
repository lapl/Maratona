#include <cstdio>

#define DIV(i) (double)(1.0/(double(i)))

double pd[1000010];
int zeros[1000010];

int main () {
	pd[1]=0.5;
	double aux2 = 5;
	zeros[1]=0;
	for(int i = 2; i < 1000010; ++i) {
		double aux = DIV(i)*DIV(i+1);
		pd[i] = pd[i-1]+aux-aux*pd[i-1];
		aux2*=aux;
		zeros[i]=zeros[i-1];
		while(aux2 < 1) {
			aux2*=10;
			++zeros[i];
		}
	}
	int n;
	while(scanf("%d",&n) ==1) {
		printf("%lf %d\n",pd[n],zeros[n]);	
	}
	return 0;
}


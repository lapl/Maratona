#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		int maior = 0;
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d",&x);
			maior = max(maior,x);
			sum+=x;
		}
		int a1=0,a2=0,a3=0;
		int aux=50;
		if(aux < sum*2) {
			a1=0;
		} else {
			if(maior <= aux) {
				a1 = (aux/maior)+1;
			}
		}
		aux = 60;
		if(aux < sum*2) {
			a2=0;
		} else {
			if(maior <= aux) {
				a2 = aux/maior+1;
			}
		}
		aux = 70;
		if(aux < sum*2) {
			a3=0;
		} else {
			if(maior <= aux) {
				a3 = aux/maior+1;
			}
		}
		printf("%d %d %d\n",a1,a2,a3);
	}
	return 0;
}


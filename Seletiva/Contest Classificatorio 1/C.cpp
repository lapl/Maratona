#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int A[10000010];
int qtd;
void calc () {
	A[1] = 1;
	A[2] = 2;
	A[3] = 4;
	A[4] = 6;
	A[5] = 9;
	A[6] = 12;
	A[7] = 16;
	qtd = 7;
	int aux = 4;
	while(A[qtd - 1] < 2000001000 ) {
		int rep = A[aux+1] - A[aux];
		while(rep &&  (A[qtd-1 ] < 2000001000 )) {
			A[qtd] = A[qtd-1]+aux;
			++qtd; --rep;
		}
		++aux;
	}

}

int main () {
	calc();
	int n;
	while(scanf("%d",&n) && n) {
		for(int i = 1; i <= qtd; ++i) if(n < A[i]) { printf("%d\n",i-1); break; }
	}
	return 0;
}


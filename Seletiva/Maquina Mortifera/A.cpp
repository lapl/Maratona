#include <cstdio>
//top, bottom, front, left, back, right.

int vertical[4][2]= {1,4,4,0,0,2,2,1};
int horizontal[4][2]= {4,5,5,2,2,3,3,4};
int profundidade[4][2]={5,0,0,3,3,1,1,5};

bool equals(int a1[6], int a2[6]) {
	for(int i = 0; i < 6; ++i) if(a1[i]!=a2[i]) return false;
	return true;
}

void f(int a1[6], int a2[6]) {
	for(int i = 0; i < 6; ++i) a2[i]=a1[i];
}

int A[6];
int B[6];

int aux[6];

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		bool ok = 0;
		for(int i = 0; i < 6; ++i) scanf("%1d",&A[i]);
		for(int i = 0; i < 6; ++i) scanf("%1d",&B[i]);
		for(int i = 0; i < 4; ++i) {
			if(i!=0) {
				f(A,aux);
				for(int k = 0; k < 4; ++k)
					A[vertical[k][0]] = aux[vertical[k][1]];
			}
			for(int j = 0; j < 4; ++j) {
				f(A,aux);
				for(int k = 0; k < 4; ++k)
					A[horizontal[k][0]] = aux[horizontal[k][1]];
				for(int l = 0; l < 4; ++l) {
					f(A,aux);
					for(int k = 0; k < 4; ++k)
						A[profundidade[k][0]] = aux[profundidade[k][1]];
						
					if(equals(A,B)) ok=1;
				}
			}
		}
				
		printf(ok ? "Equal\n" : "Not Equal\n");
	}
	return 0;
}


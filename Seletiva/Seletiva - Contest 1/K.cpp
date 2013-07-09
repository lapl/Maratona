#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,(a))
using namespace std;

typedef vector<int> vi;

double votos[110];

int main () {
	double n,p;
	while(scanf("%lf %lf",&n,&p) == 2) {
		double resta = 100-p;
		p/=100.0;
		double julio;
		scanf("%lf",&julio);
		double julio2 = julio*p;
		bool ganhou = 1;
		bool can = 1;
		double x;
		REP(i,n-1) {
			scanf("%lf",&x);   
			votos[i] = x*p;
			//printf("%lf\n", votos[i-1]);   
			if (julio <= x) can = 0;
 			ganhou&=(julio2 > (x*p + resta));
		}
		//printf("%lf %lf %lf\n", julio*p, x, x+resta);
		if(n == 1) {
			printf("S S\n");
		} else {
			sort(votos,votos+(int)n-1);
			REP(i,n-2) {
				resta-=min(votos[(int)n-2]-votos[i],resta);
				if(resta == 0) break;
			}
			if(resta != 0) {
				votos[(int)n-2]+=(resta/(n-1));
			}
			can&=(julio*p > votos[(int)n-2]);
			ganhou&=can;
			printf(can ? "S" : "N");
			printf(ganhou ? " S\n" : " N\n");
		}	
	}
	return 0;
}


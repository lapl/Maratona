#include <cstdio>


int main () {
	int hi,mi,hf,mf;
	while(1) {
		scanf("%d %d %d %d",&hi,&mi,&hf,&mf);
		if (hi == 0 && mi == 0 && hf == 0 && mf == 0) break;
		if (hf < hi) hf+=24;
		else if ((hf == hi) && (mi > mf)) hf += 24;
		printf("%d\n", (hf-hi)*60 + (mf-mi));
	}
	return 0;
}


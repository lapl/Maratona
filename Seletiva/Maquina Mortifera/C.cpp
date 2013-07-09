#include <cstdio>

const double zeroEmC = -32.0*5.0/9.0;

int main () {
	int tc; double c, f, ans;
	scanf("%d",&tc);
	for(int cases = 1; tc--; ++cases) {
		scanf("%lf %lf",&c,&f);
		ans = (f-32.0)*5.0/9.0 - zeroEmC;
		ans+=c;
		printf("Case %d: %.2lf\n",cases, ans);
	}
	return 0;
}


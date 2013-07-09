#include <cstdio>
#include <algorithm>
int main () {
	int h,m;
	while(scanf("%d:%d",&h,&m) && (h|m)) {
		double x = 30*h+0.5*m;
		double y = 6*m;
		if(y < x) std::swap(x,y);
		double ans = (y-x > 180 ? 360-y+x : y-x);
		printf("%.3lf\n",ans);
	}
	return 0;
}


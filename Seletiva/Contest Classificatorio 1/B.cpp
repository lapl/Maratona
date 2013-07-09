#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
	int n,m,c;
	while(scanf("%d %d %d",&n,&m,&c) == 3) {
		if(n == 0 && m == 0 && c == 0) break;
		int menor = min(m,n);
		if(n*m >= 64) {
			int ans = 0;
			//printf("%d\n", ans);
			if(c) {
				for(int i = 0; i <= (menor-8); ++i) {
					if((m-i)*(n-i) >= 64) ++ans;
					else break;
					ans=ans+((m-8-i)/2);
					ans=ans+((n-8-i)/2);
				}
			} else {
				for(int i = 0; i <= (menor-8); ++i) {
					ans=ans+((m-8-i+1)/2);
					ans=ans+((n-8-i+1)/2);
				}
			}
			printf("%d\n", ans);
		} else {
			printf("%d\n", 0);
		}
	}
	return 0;
}


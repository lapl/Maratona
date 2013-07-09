#include <cstdio>
#include <cmath>

using namespace std;

long long int f(int n) {
	int ret = 0;
	int aux = 5;
	while(aux <= n) {
		ret += n/aux;
		aux*=5;
	}
	return ret;
}

int main () {
	int n,tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d",&n);
		printf("%lld\n", f(n));
	}
	return 0;
}


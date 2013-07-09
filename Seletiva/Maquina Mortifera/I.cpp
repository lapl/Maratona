#include <cstdio>
#include <vector>
#define SIZE(v) (int)(v).size()
using namespace std;

int main () {
	int n,k,m;
	while(scanf("%d %d %d",&n,&k,&m) && n) {
		vector<int> v;
		for(int i = 1; i <= n; ++i) {
			v.push_back(i);
		}
		int aux = m-1;
		v.erase(v.begin()+aux);
		for(int i = 1; i < n-1; ++i) {
			aux = (aux+k-1)%(n-i);
			v.erase(v.begin()+aux);
		}
		printf("%d\\n",*v.begin());
	}
	return 0;
}


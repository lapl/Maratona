#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		int x;
		priority_queue <int, vector<int>, greater<int> > pq;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&x);
			 pq.push(x);
		}
		int ans = 0;
		while(!pq.empty()) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			ans += (a+b);
			if(!pq.empty()) pq.push(a+b);
		}
		printf("%d\n",ans);
	}
	return 0;
}


#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;



int main () {
	int n,l;
	while(scanf("%d",&n) && n) {
		scanf("%d",&l);
		AdjList.assign(n,vi());
		for(int i = 0; i < l; ++i) {
			int a,b;
			scanf("%d %d",&a,&b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		queue<int> q;
		q.push(0);
		map<int,int> dist; dist[0] = 0;
		bool ans = 1;

		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int j = 0; j < (int)AdjList[u].size(); ++j) {
				int v = AdjList[u][j];
				if(!dist.count(v)) {
					dist[v] = 1 - dist[u];
					q.push(v);
				} else if (dist[v] == dist[u]) ans = 0;
			}
		}
		printf(ans ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
	}
	return 0;
}


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

vector<vi> pilotos;
vi pont;
vi clas;

int main () {
	int g,p;
	while(scanf("%d %d",&g,&p) && g) {
		pilotos.assign(p+1,vi());
		while(g--) {
			int pos;
			for(int i = 1; i <= p; ++i) {
				scanf("%d",&pos);
				pilotos[i].push_back(pos);
			}
		}
		int s;
		scanf("%d",&s);
		while(s--) {
			int k;
			scanf("%d",&k);
			pont.assign(p+1,0);
			for(int i = 1; i <= k; ++i) {
				int x;
				scanf("%d",&x);
				pont[i] = x;
			}
			clas.assign(p+1,0);
			for(int i = 1; i <= p; ++i) {
				for(int j = 0; j < (int)pilotos[i].size(); ++j) {
					clas[i]+=(pont[pilotos[i][j]]);
				}
			}
			int maior = *max_element(clas.begin(),clas.end());
			bool first = 1;
			for(int i = 1; i <= p; ++i) {
				if(clas[i] == maior) {
					if(first) { printf("%d", i); first = 0;}
					else printf(" %d", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}


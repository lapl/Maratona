#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct team {
	int ballons;
	int da;
	int db;
	team(int ba,int a,int b) : ballons(ba),da(a),db(b) {}
	bool operator< (const team &lhs) const {
		return abs(db-da) >  abs(lhs.db-lhs.da);
	}
};


int main () {
	int N,a,b;
	vector<team> v;
	while(scanf("%d %d %d",&N,&a,&b) && N) {
		v.clear();
		int k,da,db;
		for(int i = 0; i < N; ++i) {
			scanf("%d %d %d",&k,&da,&db);
			v.push_back(team(k,da,db));
		}
		sort(v.begin(),v.end());
		int dist = 0;
		for (int i = 0; i < N; ++i) {
			team aux = v[i];
			//printf("%d %d %d\n", aux.ballons,aux.da,aux.db);
			for(int j = 0; j < aux.ballons; ++j) {
				if(aux.da <= aux.db) {
					//printf("teste1\n");
					if(a > 0) {
						dist+=(aux.da);
						--a;
					} else {
						dist+=(aux.db);
						--b;
					}
				} else {
					//printf("teste2\n");
					if(b > 0) {
						dist+=(aux.db);
						--b;
					} else {
						dist+=(aux.da);
						--a;
					}
				}
			}
			//printf("%d\n", dist);
		}
		printf("%d\n", dist);
	}
	return 0;
}


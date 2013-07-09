#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)
#define DFS_WHITE -1

using namespace std;

typedef vector<int> vi;

vi dfs_num,dfs_low,S,visited;
int dfsNumberCounter;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vi adjList[1010];
int numSCC;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	REP(j,adjList[u].size()) {
		int v = adjList[u][j];
		if(dfs_num[v] == DFS_WHITE)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]) {
		++numSCC;
		while(1) {
			int v = S.back(); S.pop_back(); visited[v]=0;
			if(u == v) break;
		}
	}
}


map<string,int> M;

int main () {
	int p,t;
	while(scanf("%d %d\n",&p,&t) && p) {
		string s,s2;
		M.clear();
		int aux = 0;
		REP(i,p) adjList[i].clear();
		dfs_num.assign(p,DFS_WHITE); dfs_low.assign(p,0); visited.assign(p,0);
		dfsNumberCounter = numSCC = 0;
		S.clear();
		REP(i,p) {
			getline(cin,s);
			M[s] = aux++;
		}
		REP(i,t) {
			getline(cin,s);
			getline(cin,s2);
			adjList[M[s]].push_back(M[s2]);
		}
		REP(i,p) if(dfs_num[i] == DFS_WHITE) tarjanSCC(i);
		printf("%d\n", numSCC);
	}
	return 0;
}                                                                                         


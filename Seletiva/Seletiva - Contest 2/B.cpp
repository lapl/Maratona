#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)
#define DFS_WHITE -1

using namespace std;

typedef vector<int> vi;

vi dfs_num,dfs_low,S,visited;
int dfsNumberCounter;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vi adjList[2010];
int numSCC;

int scc[2010];

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
		while(1) {
			int v = S.back(); S.pop_back(); visited[v]=0;
			scc[v] = numSCC;
			if(u == v) break;
		}
		++numSCC;
	}
}

map<string,int> M;

char s1[25],s2[25];
string S1,S2;

int main () {
	int n;
	int qtd = 0;
	for(int cases = 1; scanf("%d",&n) == 1; ++cases) {
		M.clear();
		qtd = 0;
		REP(i,n) {
			scanf("%s %s",s1,s2);
			bool b1 = 1,b2=1;
			if(s1[0]=='!') {
				S1 = string(s1+1,s1+strlen(s1));
				b1 = 0;
			} else S1 = s1;
			if(s2[0]=='!') {
				S2 = string(s2+1,s2+strlen(s2));
				b2 = 0;
			} else S2 = s2;
			
			if(M.find(S1) == M.end()) {
				M[S1] = qtd;
				adjList[qtd++] = vi();
				adjList[qtd++]=vi();
			}
			if(M.find(S2) == M.end()) {
				M[S2] = qtd;
				adjList[qtd++] = vi();
				adjList[qtd++]=vi();
			}
			int A = M[S1]; if(!b1) A+=1;
			int B = M[S2]; if(!b2) B+=1;
			//printf("%d %d\n",A^1,B);
			//printf("%d %d\n",B^1,A);
			adjList[A^1].push_back(B);
			adjList[B^1].push_back(A);
		}
		dfs_num.assign(qtd, DFS_WHITE); dfs_low.assign(qtd, 0);
		visited.assign(qtd, 0);
        memset(scc,-1,sizeof scc);
        dfsNumberCounter = numSCC = 0;
        for(int i = 0; i < qtd; i++)
            if(dfs_num[i] == DFS_WHITE)
                 tarjanSCC(i);
        bool ans = 1;
        for(int i = 0; i < qtd; i+=2) {
        	if(scc[i] == scc[i^1]) {
        		ans = 0;
        		break;
        	}
        }
        printf("Instancia %d\n", cases);
        printf(ans ? "sim\n\n" : "nao\n\n");
		
	}
	return 0;
}


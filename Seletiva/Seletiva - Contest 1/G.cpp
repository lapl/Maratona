#include <bits/stdc++.h>

using namespace std;

#define maxn 1005
#define maxe 10010

int adj[maxn],to[maxe],ant[maxe],z;

#define add(a,b) ant[z]=adj[a],to[z]=b,adj[a]=z++

int grundy[maxn];

int calcGrundy(int pos) {
    if(grundy[pos]!=-1) return grundy[pos];
    set<int> s;
    for(int i = adj[pos]; i != -1; i = ant[i]) {
        s.insert(calcGrundy(to[i]));
    }
    int ret = 0;
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        if(*it != ret) break;
        else ++ret;
    }
    return grundy[pos] = ret;
}

vector<int> nim;

int main() {
    int n,m;
    while(cin >> n >> m && (n|m)) {
       // cout << n << " " << m << endl;
        memset(adj,-1,sizeof adj);
        z = 0;
        for(int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            //cout << a << " " << b << endl;
            add(a,b);
        }
        memset(grundy,-1,sizeof grundy);
        for(int i = 0; i < n; ++i) {
            calcGrundy(i);   
        }
        nim.clear();  
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            //cout << x << endl;
            int aux = grundy[i];
            for(int j = 0; j < x; ++j) {
                nim.push_back(aux);
            }
        }
       // cout << "LOL\n";
        int ans = nim[0];
        for(int i = 1; i < nim.size(); ++i) {
            ans^=nim[i];
        }
        printf( ans != 0 ? "First\n" : "Second\n");
    }
    return 0;
}


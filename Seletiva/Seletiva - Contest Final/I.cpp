#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int A[100005];

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		map<int,int> m;
		vector<int> v;
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d",&x);
			m[x]=i;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i = 1; i <= n; ++i) {
			A[i] = m[v[i-1]];
			//printf("%d %d\n", i,m[v[i]]);
		}
		int ct = 0;
		bool b = 1;
		while(b) {
			b = 0;
			for(int i = 1; i <= n; ++i) {
				if(A[i]!=i) {
					int aux = A[A[i]];
					A[A[i]] = A[i];
					A[i]=aux;
					++ct;
					b = 1;
				}
			}
		}
		printf("%d\n", ct);
	}
	return 0;
}


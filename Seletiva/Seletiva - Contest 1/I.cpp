#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> VI;

void st_build(VI &t, const VI &A, int vertex, int L, int R) {
	if(L == R) t[vertex] = L;
	else {
		int mid = (L+R)>>1;
		int nL = vertex<<1, nR = (vertex<<1)+1;
		st_build(t,A,nL,L, mid);
		st_build(t,A,nR,mid+1, R);
		int lContent = t[nL], rContent = t[nR];
		int lValue = A[lContent], rValue = A[rContent];
		t[vertex] = (lValue >= rValue) ? lContent : rContent;
	}
}

void st_create(VI &t, const VI &A) {
	int len = 4 * (int)A.size() + 10;
	t.assign(len,0);
	st_build(t,A,1,0,(int)A.size()-1);
}

int st_rmq(VI &t, const VI &A, int vertex, int L, int R, int i, int j) {
	if(i > R || j < L) return -1;
	if(L >= i && R <= j) return t[vertex];
	int mid = (L+R)>>1;
	int p1 = st_rmq(t,A,vertex<<1,L,mid,i,j);
	int p2 = st_rmq(t,A,(vertex<<1)+1,mid + 1,R,i,j);
	
	if(p1 == -1) return p2;
	if(p2 == -1) return p1;
	return (A[p1] >= A[p2]) ? p1 : p2;
 }
 
 int st_rmq(VI &t, const VI &A, int i, int j) {
 	return st_rmq(t,A,1,0,(int)A.size()-1,i,j);
 }
 
 void st_update(VI &t, const VI &A, int vertex, int L, int R, int i) {
 	if(L == R) t[vertex] = L;
 	else {
 		int nL = vertex<<1, nR = (vertex<<1) + 1;
 		int mid = (L+R)>>1;
 		if(i <= mid) {
 			st_update(t, A, nL, L, mid, i);
 		} else {
 			st_update(t,A, nR, mid+1,R, i);
 		}
 		int lContent = t[nL], rContent = t[nR];
 		int lValue = A[lContent], rValue = A[rContent];
 		t[vertex] = (lValue >= rValue ? lContent : rContent);
 	}
 }
 
 void st_update(VI &t, const VI &A, int i) {
 	st_update(t,A,1,0,(int)A.size()-1,i);
 }
 
 VI v;
 VI st;
 char ch[2];
 
 int main () {
 	int n;
 	while(scanf("%d",&n) == 1) {
 		v.assign(n,0);
 		for(int i = 0; i < n; ++i) scanf("%d",&v[i]);
 		st_create(st,v);
 		int q;
 		scanf("%d",&q);
 		while(q--) {
 			int a,b;
 			scanf("%s %d %d",ch,&a,&b);
 			char c = ch[0];
 			if(c == 'U') {
 				--a;
 				v[a] = b;
 				st_update(st,v,a); 
 			} else {
 				--a; --b;
 				int pos1 = st_rmq(st,v,a,b);
 				int x = v[pos1];
 				v[pos1]=-1;
 				st_update(st,v,pos1);
 				int pos2 = st_rmq(st,v,a,b);
 				int y = v[pos2];
 				v[pos1] = x;
 				st_update(st,v,pos1);
 				printf("%d\n",x+y);
 			}
 		}
 	}
 	return 0;
 }


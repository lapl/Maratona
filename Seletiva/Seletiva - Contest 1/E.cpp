#include <bits/stdc++.h>

using namespace std;

struct tupla{
	int a, b, c;
	tupla(int a = 1, int b  = 0, int c = 0) : a(a), b(b), c(c) {}
	void imprime() { printf("%d %d %d\n",a,b,c); }
};

tupla operator +(const tupla &lhs, const tupla &rhs) {
	return tupla(lhs.a+rhs.a,lhs.b + rhs.b, lhs.c + rhs.c);
}

ostream& operator <<(ostream& os, tupla t) {
	return os << t.a << " " << t.b << " " << t.c;
}

int n;

tupla trocar (tupla t, int i) {
	int a = t.a, b = t.b, c = t.c;
	if(i%3==0) return t;
	else if(i%3==1) return tupla(c,a,b);
	else return tupla(b,c,a);
}

typedef vector <tupla> vt;

vt t; vector<int> lazy;

#define dbg(x) cout << #x << " " << x << endl;

void st_build(int vertex, int L, int R){
	if(L == R)
		t[vertex] = tupla();
	else{
		int nL = 2 * vertex, nR = 2*vertex+1;
		st_build(nL, L, (L+R)/2);
		st_build(nR, (L+R)/2+1, R);
		t[vertex] = t[nL] + t[nR];
	}
	//printf("L %d R %d\n",L,R);
	//dbg(t[vertex]);
}

void st_create(){
	int len = (int)(2*pow(2.0, floor((log((double)n)/log(2.0)) + 1)));
	t.assign(len, tupla());
	lazy.assign(len, 0);
	st_build(1, 0, n-1);
}

void update(int vertex, int L, int R, int i, int j, int value){

	if(lazy[vertex] != 0){
		t[vertex] = trocar(t[vertex], lazy[vertex]);

		if(L != R){
			lazy[vertex*2] += lazy[vertex];
			lazy[vertex*2+1] += lazy[vertex];
		}
		lazy[vertex] = 0;
	}

	if(i > R || j < L) return;

	if(L >= i && R <= j){
		t[vertex] = trocar(t[vertex],value);
		if(L != R){
			lazy[vertex*2+1] += value;
			lazy[vertex*2] += value;
		}
		return;
	}

	update(vertex*2, L, (L+R)/2, i, j, value);
	update(vertex*2+1, (L+R)/2+1, R, i, j, value);

	t[vertex] = t[vertex*2] + t[vertex*2+1];
}

void update(int i, int j, int value){
	return update(1, 0, n-1, i, j, value);
}

tupla query(int vertex, int L, int R, int i, int j){

	if(lazy[vertex] != 0){
		t[vertex] = trocar(t[vertex],lazy[vertex]);

		if(L != R){
			lazy[vertex*2] += lazy[vertex];
			lazy[vertex*2+1] += lazy[vertex];
		}
		lazy[vertex] = 0;
	}

	if(i > R || j < L) return 0;

	if(L >= i && R <= j) return t[vertex];

	tupla q1 = query(vertex*2, L, (L+R)/2, i, j);
	tupla q2 = query(vertex*2+1, (L+R)/2+1, R, i, j);

	return q1+q2;
}

tupla query(int i, int j){
	return query(1, 0, n-1, i, j);
}

int main(){
	int m;
	while(scanf("%d %d",&n,&m)==2) {
		st_create();
		for(int i = 0; i < m; ++i) {
			char ch[2];
			int a,b;
			scanf("%s %d %d",ch,&a,&b);
			--a; --b;
			if(ch[0]=='M') update(a,b,1);
			if(ch[0]=='C') query(a,b).imprime();
		}
		printf("\n");
	}
	return 0;
}


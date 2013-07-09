#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX_N 3

typedef unsigned long long ll;

struct Matrix { ll mat[MAX_N][MAX_N]; };

Matrix matMult(const Matrix& a, const Matrix& b, ll mod) {
	Matrix ans; ll k;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			for(ans.mat[i][j] = k = 0; k < 2; ans.mat[i][j]%=mod, ++k)
				ans.mat[i][j]+=((a.mat[i][k]%mod)*(b.mat[k][j]%mod))%mod;
	return ans;
}

Matrix fastExp(Matrix base, ll p, ll mod) {
	Matrix ans;
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			ans.mat[i][j] = (i==j);
	while(p) {
		if(p&1) ans = matMult(ans,base,mod);
		base = matMult(base,base,mod);
		p>>=1;
	}
	return ans;
}

int main () {
	ll n,m;
	Matrix M;
	M.mat[0][0]=1;
	M.mat[1][0]=1;
	M.mat[0][1]=1;
	M.mat[1][1]=0;
	while(scanf("%lld %lld", &n, &m) == 2) {
		Matrix ans = fastExp(M,n,pow(2,m));
		printf("%lld\n",ans.mat[1][0]);
	}
	return 0;
}


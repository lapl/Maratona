#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  double z,w;
  PT() {}
  PT(double x, double y, double z = 0.0, double w = 0.0) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y), z(p.z), w(p.w)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator < (const PT &p) const {
  	return x < p.x;
  }
};

PT A[16];

typedef pair<double,double> PDD;

PT novo(int j) {
	PT p;
	PT a = A[j];
	PT b = A[j+1];
	//cout << a.z << " " << b.w << endl;
	p.x = (a.z+b.w)/2.0;
	//cout << p.x << endl;
	p.w = b.w;
	p.z = a.z;
	double aux = (p.x-a.x)*(p.x-a.x);
	double delta = 4.0*a.y*a.y - 4.0*(a.y*a.y+aux-4.0);
	p.y = (2.0*a.y + sqrt(delta))/2.0;
	return p;
}

int main () {
	int n;
	while(scanf("%d",&n) && n) {
		REP(i,n) {
			double x;
			scanf("%lf",&x);
			A[i].z = x;
			A[i].w = x;
			A[i].x = x;
			A[i].y = 1.0;
		}
		
		sort(A,A+n);		
		
		FORD(i,n,2) {
			//cout << "nivel " << i << endl;
			REP(j,n-1)
				A[j]=novo(j);
		}
		printf("%.4lf %.4lf\n",A[0].x,A[0].y);
		
	}
	return 0;
}


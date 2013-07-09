#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

double DistancePointSegment(PT a, PT b, PT c, PT *d) {
	*d = ProjectPointSegment(a, b, c);
  	return sqrt(dist2(c, *d));
}
 
 int main () {
 	int n;
	PT m;
	while(scanf("%lf %lf",&m.x,&m.y) == 2) {
		scanf("%d",&n);
		PT a;
		double menor = 1000000;
		scanf("%lf %lf",&a.x,&a.y);
		PT b;
		PT ans(0,0);
		for(int i = 0; i < n; ++i) {
			scanf("%lf %lf",&b.x,&b.y);
			PT p;
			double aux = DistancePointSegment(a,b,m,&p);
			if(aux < menor) {
				menor = aux;
				ans = p;
			}
			a = b;
		}
		printf("%.4lf\n%.4lf\n",ans.x,ans.y);	
	}
	return 0;
 }


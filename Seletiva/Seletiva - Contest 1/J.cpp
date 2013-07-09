#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <cstring>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,(a))
#define LSOne(S) (S & (-S))
#define INF 1000000000
#define EPS 1e-12
using namespace std;

typedef vector<int> vi;

struct PT {
	double x,y;
	PT() {}
	PT(double x, double y) : x(x),y(y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x,y-p.y);}
	PT operator * (double c) const { return PT(x*c, y*c);}
};

double dot(PT p, PT q) { return p.x*q.x+p.y*q.y;}
double dist2(PT p, PT q) { return dot(p-q,p-q);}
double cross(PT p, PT q) { return p.x*q.y-p.y*q.x;}

bool linesParallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b-a,c-d)) < EPS;
}

bool linesCollinear(PT a, PT b, PT c, PT d) {
	return linesParallel(a,b,c,d) && fabs(cross(a-b,a-c)) < EPS;
}

bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if(linesCollinear(a,b,c,d)) {
		if(dist2(a,c) < EPS || dist2(a,d) < EPS ||
			dist2(b,c) < EPS || dist2(b,d) < EPS) return true;
		if(dot(c-a,c-b) > 0 && dot(d-a,d-b) > 0 && dot(c-b,d-b) > 0) return false;
		return true;
	}
	if(cross(d-a,b-a) * cross(c-a,b-a) > 0) return false;
	if(cross(a-c,d-c) * cross(b-c,d-c) > 0) return false;
	return true;
}


struct X {
	PT a, b;
};

int main () {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		scanf("%d",&n);
		vector<X> v;
		v.assign(n,X());
		REP(i,n) {
			double a,b,c,d;
			scanf("%lf %lf %lf %lf",&a, &b, &c, &d);
			v[i].a = PT(a,b);
			v[i].b = PT(c,d);
		}
		int ans = n;
		REP(i,n) FOR(j,i+1,n) {
			if(SegmentsIntersect(v[i].a,v[i].b,v[j].a,v[j].b)) ans+=2;
		}
		printf("%d\n", ans);
		if(tc) printf("\n");
	}
	return 0;
}


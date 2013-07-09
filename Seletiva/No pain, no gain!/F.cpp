#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

struct point {
	double x, y;
	point() : x(0.0), y(0.0) {}
  	point(double _x, double _y) : x(_x), y(_y) {} 
  	bool operator == (const point &lhs) const {
  		return fabs(x - lhs.x) < EPS && (fabs(y-lhs.y) < EPS);
  	}
};


struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line *l) {
	if (fabs(p1.x - p2.x)<EPS) {
  		l->a = 1.0;   l->b = 0.0;   l->c = -p1.x;
  	}
 	else {
    	l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    	l->b = 1.0;
   		l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
	}
}


bool areParallel(line l1, line l2) {
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
  return (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point *p) {

  p->x = (double)(l2.b * l1.c - l1.b * l2.c) / 
                 (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p->y = - (l1.a * p->x + l1.c) / l1.b;
  else
    p->y = - (l2.a * p->x + l2.c) / l2.b;
  return true;
}

int main () {
	int n;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--) {
		point a, b, c, d;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		line l1,l2;
		pointsToLine(a,b,&l1);
		pointsToLine(c,d,&l2);
		if(areParallel(l1,l2)) {
			if(areSame(l1,l2)) printf("LINE\n");
			else printf("NONE\n");
		} else {
			point ans;
			areIntersect(l1,l2,&ans);
			printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}


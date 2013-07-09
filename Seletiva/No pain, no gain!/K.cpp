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
  	bool operator < (point other) {
    	if (fabs(x - other.x) > EPS)
      		return x < other.x;
    	return y < other.y;
    }
};

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

double angle(point a, point b, point c) {
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;
  return acos((ux*vx + uy*vy) / 
              sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy))); }

bool inPolygon(point p, const vector<point>& P) {
  if ((int)P.size() == 0) return false;
  double sum = 0;
  for (int i = 0; i < (int)P.size() - 1; i++) {
    if (cross(p, P[i], P[i + 1]) < 0)
         sum -= angle(p, P[i], P[i + 1]);
    else sum += angle(p, P[i], P[i + 1]);
  }
  return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
}



int inCircle(point p, point c, double r) {
  double dx = p.x - c.x, dy = p.y - c.y;
  double Euc = dx * dx + dy * dy, rSq = r * r;
  return (Euc - rSq) < EPS;
}

struct circle {
	point c; double r;
	int num;
};

struct triangle {
	vector<point> p;
	int num;
};

struct rect {
	double x1,x2,y1,y2;
	int num;
};

bool inRectangle(point p, const rect& r) {
	//cout << p.x << " " << p.y << endl;
	//cout << r.x1 << " " << r.x2 << " " << r.y1 << " " << r.y2 << endl;
	return (p.x > r.x1 && (p.x < r.x2) && (p.y < r.y1) && (p.y > r.y2));
}

vector<triangle> T;
vector<circle> C;
vector<rect> R;

int main () {
	for(int i = 1; ; ++i) {
		char ch[2];
		scanf("%s",ch);
		//cout << ch << endl;
		if(ch[0] == '*') break;
		if(ch[0] == 'r') {
			rect r;
			cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
			r.num = i;
			//cout << i << endl;
			R.push_back(r);		
		} else if(ch[0] == 'c') {
			circle c;
			cin >> c.c.x >> c.c.y >> c.r;
			c.num = i;
			C.push_back(c);
		} else {
			triangle t;
			for(int j = 0; j < 3; ++j) {
				point p;
				cin >> p.x >> p.y;
				t.p.push_back(p);
			}
			t.p.push_back(t.p[0]);
			t.num = i;
			T.push_back(t);
		}
	}
	for(int pt = 1; ; ++pt) {
		point p;
		cin >> p.x >> p.y;
		if(fabs(p.x - 9999.9) < EPS &&  fabs(p.y - 9999.9) < EPS) break;
		vector<int > v;
		for(int i = 0; i < (int)T.size(); ++i) {
			if(inPolygon(p, T[i].p)) {
				v.push_back(T[i].num);
			}	
		}
		for(int i = 0; i < (int)R.size(); ++i) {
			//cout << T[i].num << endl;
			if(inRectangle(p,R[i])) {
				v.push_back(R[i].num);
			}
		}
		for(int i = 0; i < (int)C.size(); ++i) {
			if(inCircle(p,C[i].c,C[i].r)) {
				v.push_back(C[i].num);
			}
		}
		sort(v.begin(),v.end());
		if((int)v.size()) {
			for(int i = 0; i < (int)v.size(); ++i) {
				printf("Point %d is contained in figure %d\n",pt,v[i]);
			}
		} else {
			printf("Point %d is not contained in any figure\n",pt);
		}
	}
	return 0;
}


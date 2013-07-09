#include <cstdio>
#include <cmath>
#include <iostream>
#define PI acos(-1.0)

long double L,W,x,y,R,a,v,s;

using namespace std;

long double DEG_to_RAD(long double d) { return d * PI / 180.0; }

long double f(long double coord, long double dist, long double side) {
	long double temp = coord+dist;
	if(temp >= R && (temp <= side-R)) return temp;
	temp = side-2*R;
	long double prev = dist;
	dist = fabs(dist);
	dist = (prev > 0) ? dist-(side-R-coord) : dist-(coord-R); 
	long long vezes = dist/temp;
	long double resto = fmod(dist,temp);
	if((vezes&1 && prev < 0) || (vezes%2==0 && prev > 0)) {
		return side-R-resto;
	} else return R+resto;
}

int main () {
	while(scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf",&L,&W,&x,&y,&R,&a,&v,&s) == 8) {
		if(L == 0.0 && R == 0.0 && x == 0.0 && y == 0.0 && R == 0.0 && a == 0.0 && v == 0.0 && s == 0.0) break;
		a = DEG_to_RAD(a);
		long double vx = v*cos(a);
		long double vy = v*sin(a);
		long double distx = vx*s;
		long double disty = vy*s;
		//cout << distx << endl;
		//cout << disty << endl;
		long double ansx = f(x,distx,L);
		long double ansy = f(y,disty,W);
		printf("%.2Lf %.2Lf\n",ansx,ansy);
	}	
	return 0;
}


#include <cstdio>
#include <cmath>

#define PI acos(-1.0)

int main () {
    double a,b,c,d,e,r1,r2;
    while(scanf("%lf %lf",&a,&b)==2) {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r1);
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r2);
        printf("%.6lf\n",PI*(r1*r1+r2*r2));
    }
    return 0;
}


#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int tri[3];

int main () {
	int tc;
	scanf("%d",&tc);
	for(int cases = 1; tc--; ++cases) {
		for(int i = 0; i < 3; ++i) scanf("%d",&tri[i]);
		sort(tri,tri+3);
		printf("Case %d: ", cases);
		if((tri[0] < 1 ) || tri[2]-tri[0] >= tri[1]) printf("Invalid\n");
		else {
			if(tri[2] == tri[0] && tri[0] == tri[1]) printf("Equilateral\n");
			else if(tri[0]==tri[1] || (tri[0]==tri[2]) || (tri[1]==tri[2])) printf("Isosceles\n");
			else printf("Scalene\n");
		}
	}
	return 0;
}


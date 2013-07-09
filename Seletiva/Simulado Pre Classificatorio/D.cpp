#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define mp make_pair
#define pb push_back
#define ALL(c) (c.begin(),c.end())

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;


char grid[65][65];


int main () {
	int tc;
	scanf("%d",&tc);
	int first = 1;
	while(tc--) {
		first ? first = 0: printf("\n");
		int x,y,row,col;
		scanf("%d %d\n",&row,&col);
		for(int i = 0; i < row; ++i) {
			gets(grid[i]);
		}
		char orienta = 'N';
		scanf("%d %d",&x,&y);
		--x;--y;
		char ch;
		while(scanf("%c",&ch)&& ch != 'Q') {
			if(ch == ' ' || ch == '\n') continue;
			//printf("%c\n", ch);
			switch(ch) {
				case 'R':
				switch(orienta) {
					case 'N':
					orienta = 'E';
					break;
					case 'E':
					orienta = 'S';
					break;
					case 'S':
					orienta = 'W';
					break;
					case 'W':
					orienta = 'N';
					break;
				}
				break;

				case 'L':
				switch(orienta) {
					case 'N':
					orienta = 'W';
					break;
					case 'E':
					orienta = 'N';
					break;
					case 'S':
					orienta = 'E';
					break;
					case 'W':
					orienta = 'S';
					break;
				}
				break;

				case 'F':
				switch(orienta) {
					case 'N':
					if(x-1 >= 0 && (grid[x-1][y] != '*')) x-=1;
					break;
					case 'E':
					if(y+1 < col && (grid[x][y+1] != '*')) y+=1;
					break;
					case 'S':
					if(x+1 < row && (grid[x+1][y] != '*')) x+=1;
					break;
					case 'W':
					if(y-1 >= 0 && (grid[x][y-1] != '*')) y-=1;
					break;
				}
				break;
			}
		}
		printf("%d %d %c\n", x+1,y+1,orienta);
	}
	return 0;
}


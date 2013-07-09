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
#include <stack>

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

char str[55];

int main () {
	int tc;
	scanf("%d",&tc);
	for(int cases = 1; tc--; ++cases) {
		char end;
		scanf("%s = %c",str,&end);
		//cout << str << " " << end << endl;
		int e = (end == 't');
		int len = strlen(str);
		stack<int> s1;//t | f
		stack<char> s2;//&, |, ! etc
		REP(i,len) {
			char c = str[i];
			//cout << c << endl;
			/*vector<char> v;
			while(!s2.empty()) {
			    char c = s2.top(); s2.pop();
			    //cout << c << endl;
			    v.PB(c);
			}
            FORD(i,SIZE(v)-1,0) {
                s2.push(v[i]);
            }*/
            //cout << endl;
   			if(c == 't' || c == 'f') {
				s1.push(c == 't');
			} else {
				if(c == ')') {
					while(1) {
						char front = s2.top(); s2.pop();
						if(front == '(') break;
						if(front == '!') {
							int b1 = s1.top(); s1.pop();
							s1.push(!b1);
							continue;
						}
						int b1 = s1.top(); s1.pop();
						int b2 = s1.top(); s1.pop();
						if(front == '&') {
							s1.push(b1&b2);
						} else if(front == '|') {
							s1.push(b1|b2);
						}
					}
				}
				else {
				    //s2.push(c);
					if(c == '(') { s2.push(c); continue; }
					while(!s2.empty()) {
						char front = s2.top();
						if (front == '(') {
							break;
						} else if(c != '!' || (front == '!')) {
							s2.pop();
							if(front == '!') {
								int b1 = s1.top(); s1.pop();
								s1.push(!b1);
								break;
							}
							int b1 = s1.top(); s1.pop();
							int b2 = s1.top(); s1.pop();
							if(front == '&') {
								s1.push(b1&b2);
							} else if(front == '|') {
								s1.push(b1|b2);
							}
						} else break;
					}
					s2.push(c);
				}
			}
		}
		//cout << s2.size() << endl;
		while(!s2.empty()) {
		    char front = s2.top(); s2.pop();
			if(front == '!') {
			    int b1 = s1.top(); s1.pop();
			    s1.push(!b1);
			    continue;
		    }
			int b1 = s1.top(); s1.pop();
			int b2 = s1.top(); s1.pop();
			if(front == '&') {
				s1.push(b1&b2);
			} else if(front == '|') {
				s1.push(b1|b2);
			}
		}
		if(s1.top() != e) printf("%d: Bad brain\n",cases);
		else printf("%d: Good brain\n",cases);
	}
	return 0;
}


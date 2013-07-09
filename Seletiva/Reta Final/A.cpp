#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#define INT_MAX "2147483647"

using namespace std;

typedef unsigned long long LL;

int main () {
	string s1,s2,op;
	int x,y;
	while(cin >> s1 >> op >> s2) {
		printf("%s %s %s\n",s1.c_str(),op.c_str(),s2.c_str());
		istringstream is(s1);
		is >> x;
		istringstream is2(s2);
		is2 >> y;
		bool ok = 1;
		if(x == 2147483647 && (s1 != INT_MAX)) { printf("first number too big\n"); ok = 0; }
		if(y == 2147483647 && (s2 != INT_MAX)) { printf("second number too big\n"); ok = 0; }
		if(x == 0 || y == 0) continue;
		if(!ok) printf("result too big\n");
		else {
			if(op[0] == '*') {
				LL testa = (LL)x*(LL)y;
				if(testa > 2147483647) printf("result too big\n");
			} else {
				LL testa = (LL)x+(LL)y;
				if(testa > 2147483647) printf("result too big\n");
			}
		}
	}
	return 0;
}


#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

int a[11];
int b[11];

char sc[12];
char sc2[12];

int main () {
	while(1) {
		scanf("%s %s",sc,sc2);
		if(sc[0] == '0' && sc2[0] == '0') break;
		string s = sc;
		string s2 = sc2;
		int maior = max(s.size(),s2.size());
		for(int i = 0; i < maior; ++i) {
			if (i < s.size()) a[i] = s[s.size()-i-1]-'0';
			else a[i] = 0;
		}
		for(int i = 0; i < maior; ++i) {
			if (i < s2.size()) b[i] = s2[s2.size()-i-1]-'0';
			else b[i] = 0;
		}
		int ans = 0;
		for(int i = 0; i < maior; ++i) {
			if(a[i]+b[i] >= 10) {
				++ans;
				++a[i+1];
			}
		}
		if(ans == 0) printf("No carry operation.\n");
		else if (ans == 1) printf("%d carry operation.\n", ans);
		else printf("%d carry operations.\n", ans);
	} 
	return 0;
}


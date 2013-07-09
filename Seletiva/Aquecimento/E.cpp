#include <cstdio>
#include <cstring>

int f (char ch) {
	if (ch >= 'a') return ch - 'a';
	else return ch - 'A';
}

char line[1500];

int main () {
	while(gets(line) && (line[0] != '*')) {
		int key = f(line[0]);
		int len = strlen(line);
		bool k = 0;
		bool r = 1;
		for(int i = 1; i < len; ++i) {
			if (k == 1) {
				if(f(line[i]) != key) r = 0;
				k = 0;
			}
			if (line[i] == ' ') k = 1;
		}
		r ? printf("Y\n") : printf("N\n");;
	}
	return 0;
}


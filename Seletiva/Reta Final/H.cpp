#include <cstdio>
#include <cstring>

char str[5000];

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c>='A' && c<='Z');
}

/*
int main () {
	gets(str);
	int size = strlen(str);
	int aux = 0;
	for(int i = 0; i < 64; ++i) {
		printf("%.4x\n",i);
	}
	printf("%.4x: ",0);
	for(int i = 0; i < size; ++i) {
		printf("%x",str[i]);
		++aux;
		if(!(aux%2)) printf(" ");
	}
	for(int i = 0; i < size; ++i) {
		if(!isLetter(str[i])) continue;
		if(str[i]>='a'&&str[i]<='z') str[i]-=32;
		else str[i]+=32;
	}
	printf("%28s",str);
	return 0;
}
*/

char out[5000];

int main () {
	while(1) {
		if(!gets(str)) return 0;
		int size = strlen(str);
		bool ok = 0;
		for(int i = 0; !ok ; i+=16) {
			printf("%.4x: ",i);
			int aux = 0;
			int end = i+16;
			int j;
			for(j = i; j < size && j < end; ++j) {
				printf("%x",str[j]);
				if(!((j+1)%2)) printf(" ");
			}
			int k=0;
			for(j = i, k = 0; j < size && j < end; ++j,++k) {
				if(j==size-1)ok=1;
				if(!isLetter(str[j])) {out[k] = str[j]; continue;}
				if(str[j]>='a'&&str[j]<='z') out[k] = str[j]-32;
				else out[k]=str[j]+32;
			}
			out[k]='\0';
			if(ok) {
				for(int k = j; k < end; ++k) {
					printf("  ");
					if(!(k%2)) printf(" ");
				}
			}
			if(j&1) printf(" ");
			printf("%s\n",out);
		}
	}
}


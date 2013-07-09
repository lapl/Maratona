#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 10000010

char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;

void kmpPreprocess() {
  int i = 0, j = -1; b[0] = -1; 
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j]; 
    i++; j++; 
    b[i] = j; 
} }       

void kmpSearch() { 
  int i = 0, j = 0; 
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++; j++;
    if (j == m) {
      printf("%d\n", i - j);
      j = b[j];
} } }

int main() {

	while(scanf("%d",&m)==1) {
		scanf("%s",P);
		scanf("%s",T);
		n = (int)strlen(T);
		kmpPreprocess();
		kmpSearch();
		printf("\n");
	}

  return 0;
}


#include <cstdio>

int abs2 (int num) {
	int resposta;
	num > 0 ? resposta = num : resposta = -num;
	return resposta;
}

int main () {
	int X1, Y1, X2, Y2;
	scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	while (X1 != 0 || X2 != 0 || Y1 != 0 || Y2 != 0) {
		if ((X2 == X1) && (Y1 == Y2)) printf("0\n");
		else if ((X2 == X1) || (Y2 == Y1)) printf("1\n");
		else if (abs2(X2 - X1) == abs2(Y2 - Y1)) printf("1\n");
		else printf("2\n");
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
	}
	return 0;
}


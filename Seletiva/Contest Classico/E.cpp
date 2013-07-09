#include <cstdio>
#include <cstdlib>

int N,dim,table[9][9],line[9],column[9],subRect[9];
bool sol;

int f(int row, int col) {
	int x = N*(row/N), y = col/N;
	return x + y;
}

int can(int num, int row, int col) {
	return (line[row]|column[col]|subRect[f(row,col)])&(1<<num);
}

void backtrack(int row, int col) {
	if(row == dim) { sol = 1; return;}
	if(table[row][col]) {
		if(col != (dim-1)) backtrack(row,col+1);
		else backtrack(row+1,0);
	}
	else {
		for(int num = 1; num <= dim; ++num) {
			if(can(num,row,col) == 0) {
				line[row]|=(1<<num);
				column[col]|=(1<<num);
				subRect[f(row,col)]|=(1<<num);
				table[row][col] = num;
				if(col == dim-1) backtrack(row+1,0);
				else backtrack(row,col+1);
				if(sol) return;
				table[row][col] = 0;
				line[row]&= ~(1<<num);
				column[col]&= ~(1<<num);
				subRect[f(row,col)]&= ~(1<<num);
			}
		}
	}
}

bool first = 1;
int main () {
	while(scanf("%d",&N) == 1) {
		dim=N*N;
		sol = 0;
		first ? first = 0 : printf("\n");
		for(int i = 0; i < dim; ++i) line[i] = column[i] = subRect[i] = 0;
		for(int i = 0; i < dim; ++i)
			for(int j = 0; j < dim; ++j) {
				scanf("%d",&table[i][j]);
				if(table[i][j] != 0) {
					line[i]|=(1<<table[i][j]);
					column[j]|=(1<<table[i][j]);
					subRect[f(i,j)]|=(1<<table[i][j]);
				}
			}
		backtrack(0,0);
		if(sol) {
			for(int i = 0; i < dim; ++i)
				for(int j = 0; j < dim; ++j)
					j == (dim-1) ? printf("%d\n", table[i][j]) : printf("%d ", table[i][j]);
		} else {
			printf("NO SOLUTION\n");
		}
	}
	return 0;
}


#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
ll sieve_size;
bool bs[10000010];

void sieve(ll upperbound) {
	sieve_size = upperbound + 1;
	memset(bs,1,sizeof bs);
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
	}
}

ll sol[4];ll N; bool s;

int main() {
	sieve(10000000);
	while(scanf("%llu",&N) != EOF) {
		s = 0;
		if(N<=7) printf("Impossible.\n");
		else {
			if(N % 2 == 0) {
				sol[0] = sol[1] = 2;
				N-=4;
			} else {
				sol[0] = 2;
				sol[1] = 3;
				N-=5;
			}
			for (ll i = 2; i < N; ++i) {
				if(bs[i] && bs[N-i]) {
					sol[2] = i;
					sol[3] = (N-i);
					s = 1;
					break;
				}
			}
			if(s) {
				printf("%llu", sol[0]);
				for(int i = 1; i < 4; ++i) printf(" %llu", sol[i]);
				printf("\n");
			} else {
				printf("Impossible.\n");
			}	
		}
	}
	return 0;
}


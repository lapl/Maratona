#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll sieve_size;
bitset<1000000> bs;
vi primes;

void sieve(ll upperbound) {
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; ++i)if(bs[i]) {
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;
		primes.push_back(i);
	}
}

int numDiv(int N) {
	int ret=1;
	int PF_idx = 0, PF = primes[PF_idx];
	while(N != 1 && (PF*PF <= N)) {
		int aux = 0;
		while(N % PF == 0) {
			N/=PF;
			++aux;
		}
		++aux;
		ret*=aux;
		PF = primes[++PF_idx];
	}
	if(N!=1)ret*=2;
	return ret;
}

int divisor[1000000];
int resp[1000000];

int main () {
	sieve(10000);
	for(int i = 1; i <= 1000000; ++i) divisor[i]=numDiv(i);
	resp[1]=1;
	for(int i = 2; i <= 1000000;++i) {
		if(divisor[resp[i-1]] > divisor[i]) resp[i]=resp[i-1];
		else resp[i] = i;
	}
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		int n;
		scanf("%d",&n);
		printf("%d\n",resp[n]);
	}
	return 0;
}


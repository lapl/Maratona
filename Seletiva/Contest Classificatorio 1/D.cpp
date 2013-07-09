#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define mp make_pair
#define pb push_back
#define ALL(c) (c.begin(),c.end())

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

ll sieve_size;
bitset<1000000> bs;
vll primes;

void sieve(ll upperbound) {
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; ++i)if(bs[i]) {
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;
		primes.push_back(i);
	}
}
set<ll> factors;
void primeFactors(ll N) {
	factors.clear();
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N != 1 && (PF*PF <= N)) {
		while(N % PF == 0) {
			N/=PF; factors.insert(PF);
		}
		PF = primes[++PF_idx];
	}
	if(N!= 1) factors.insert(N);
}

bool isPrime(ll N) {
	if(N <= sieve_size) return bs[N];
	for(int i = 0; i < (int)primes.size(); ++i) {
		if(N % primes[i] == 0) return 0;
	}
	return 1;
}

int main () {
	sieve(1000000);

	ll n;
	while(scanf("%lld",&n) && n) {
		if(n < 0) n = -n;
		if(isPrime(n)) printf("-1\n");
		else {
			primeFactors(n);
			if(factors.empty() || (factors.size() == 1)) printf("-1\n");
			else {
				printf("%lld\n", *(factors.rbegin()));
			}
		}
	}
	return 0;
}


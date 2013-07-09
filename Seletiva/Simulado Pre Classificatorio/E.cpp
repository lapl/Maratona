#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
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

ll sieve_size;
bitset<1000020> bs;

void sieve(ll upperbound) {
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; ++i)if(bs[i]) {
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j] = 0;
	}
}


int main () {
	sieve(1000010);
	ll n;
	while(scanf("%lld",&n) && n) {
		if(n&1) {
			printf("Goldbach's conjecture is wrong.\n");
		} else {
			for(ll i = 2; i <= n; ++i) {
				if(bs[i] && bs[n-i]) {
					printf("%lld = %lld + %lld\n", n,i,n-i);
					break;
				}
			}
		}
	}
	return 0;
}


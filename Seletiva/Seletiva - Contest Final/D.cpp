#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll sieve_size;
bitset<10000010> bs;
ll primes[80000];
int ind;

void sieve(ll upperbound) {
	sieve_size = upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(ll i = 2; i <= sieve_size; ++i) if(bs[i]) {
		for(ll j = i*i; j <= sieve_size; j+=i) bs[j]=0;
		primes[ind++]=i;
	}
}

bool isPrime(ll N) {
	if(N <= sieve_size) return bs[N];
	for(int i = 0; i < ind; ++i)
		if(N % primes[i]==0) return false;
	return true;
}

int process(ll N) {
	int ret = 0;
	ostringstream os;
	os << N;
	string s = os.str();
	map<ll,bool> used;
	for(int i = 0; i < (int)s.size(); ++i) {
		ostringstream os2;
		os2 << s.substr(0,(i+1));
		os2 << "0";
		os2 << s.substr(i+1,(int)s.size()-(i+1));
		string s2 = os2.str();
		istringstream is(s2);
		ll n;
		is >> n;
		//cout << n << endl;
		if(isPrime(n)) if(!used[n]) {++ret; used[n]=1;}
	}
	for(int i = 0; i < (int)s.size(); ++i) {
		if(s[i]=='0') {
			ostringstream os2;
			os2 << s.substr(0,i);
			os2 << s.substr(i+1,(int)s.size()-(i));
			string s2 = os2.str();
			istringstream is(s2);
			ll n;
			is >> n;
			//cout << n << endl;
				if(isPrime(n)) if(!used[n]) {++ret; used[n]=1;}
		}
	}
	return ret;
}


int main () {
	ind = 0;
	sieve(100000);
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		ll n;
		scanf("%lld",&n);
		printf("%d\n",process(n));
	}
	return 0;
}


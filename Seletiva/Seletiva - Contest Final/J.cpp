#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main () {
	double a,n;
	cout.precision(6);
	while(cin >> a >> n) {
		cout << fixed << (1-pow(1-pow(1-1/a,a-1)*1/a,n)) << endl;
	}
	return 0;
}


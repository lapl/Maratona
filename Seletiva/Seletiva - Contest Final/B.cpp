#include <bits/stdc++.h>
#define fr(i,a,b) for (int i = (a);  i < (b); ++i)
using namespace std;

typedef unsigned long long ull;

const ull B = 27ULL;

char str[40010];

ull P[40010];
ull hash[40010];

struct coisa {
	int rank; ull hash;
	coisa(){}
	bool operator<(const coisa& x) const {
		if(hash!=x.hash) return hash<x.hash;
		return rank<x.rank;
	}
};

coisa arr[40010];

int main() {
	int m;
	P[0]=1;
	fr(i,1,40010) P[i]=P[i-1]*B;
	while(scanf("%d",&m)&&m) {
		scanf("%s",str);
		int len=strlen(str);
		
		hash[0]=0;
		fr(i,1,len+1) {
			hash[i]=hash[i-1]*B+str[i-1]-96;
		}
		int lo=1,hi=len+1;
		int tam=0;
		int	posi=0;
		fr(k,0,20){
			int mid=lo+(hi-lo)/2;
			
			int n=len-mid+1;
			fr(i,0,n) {
				arr[i].rank=i;
				arr[i].hash=hash[i+mid]-hash[i]*P[mid];	
			}
			sort(arr,arr+n);
			int ct=0;
			int pos=-1;
			fr(i,0,n) {
				if(!i||arr[i].hash!=arr[i-1].hash)ct=0;
				if(++ct>=m) { 	
					pos=max(pos,arr[i].rank);
				}
			}
			if(pos>=0) {
				tam=mid;
				posi=pos;
				lo=mid;
			} else hi=mid;
		}
		if(tam==0) {
			printf("none\n");
		} else {
			printf("%d %d\n",tam,posi);
		}
		
	}
	return 0;
}

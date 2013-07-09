#include <cstdio>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

int A[1010];

int f1(int aux) {
    return A[0]+2*A[1]+A[aux+1];
}

int f2(int aux) {
    return 2*A[0]+A[aux]+A[aux+1];
}

int main () {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; ++i) {
            scanf("%d",&A[i]);
        }
        sort(A,A+n);
        int sum = 0;
        ostringstream os;
        if(n == 1) {
            printf("%d\n%d\n",A[0],A[0]);
            if(tc) printf("\n");
            continue;
        } else if(n==2) {
            printf("%d\n",A[1]);
            printf("%d %d\n",A[0],A[1]);
            if(tc) printf("\n");
            continue;
        }
        for(int i = n-2; i >= 1; i-=2) {
            if(i==1) {
               sum+=(A[0]+A[1]+A[2]);
               os << A[0] << " " << A[2] << endl;
               os << A[0] << endl;
               os << A[0] << " " << A[1] << endl;
               break;
            }
            int aux1 = f1(i);
            int aux2 = f2(i);
            if(aux1 < aux2) {
                sum+=aux1;
                os << A[0] << " " << A[1] << endl;
                os << A[0]<< endl;
                os << A[i] << " " << A[i+1] << endl;
                os << A[1] << endl;
            } else {
                sum+=aux2;
                os << A[0] << " "<< A[i+1]<<endl;
                os << A[0]  << endl;
                os << A[0] << " "<< A[i]<<endl;
                os << A[0] << endl;
                
            }
            if(i == 2) {
                sum+=A[1];
                os << A[0] << " " << A[1] << endl;
                break;
            }
        }
        printf("%d\n",sum);
        printf("%s",os.str().c_str());
        if(tc) printf("\n");
    }
    return 0;
}


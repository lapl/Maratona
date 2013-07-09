#include <cstdio>
 
int main () {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int n;
        scanf("%d",&n);
        if(n == 1) printf("0\n");
        else printf("%d\n",n-2);
    }
    return 0;
}


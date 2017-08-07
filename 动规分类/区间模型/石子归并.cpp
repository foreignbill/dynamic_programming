#include <bits/stdc++.h>
#define N 210
using namespace std;
int dp[N][N],sum[N];
int main(){
    int n;
    while(~scanf("%d",&n)){
        int a[N];sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        int i,j,l,k;
		for(l = 2; l <= n; ++l){
			for(i = 1; i <= n - l + 1; ++i){
				j = i + l - 1;
				dp[i][j] = INT_MAX;
				for(k = i; k < j; ++k){
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1]);
				}
			}
		}
		printf("%d\n", dp[1][n]);
    }
    return 0;
}


//hdu 3496
#include <bits/stdc++.h>
using namespace std;
int val[111],Time[111],dp[111][1111];
int main(){
    int T;cin>>T;
    while(T--){
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        int i,j,k;
        for(i=0;i<n;i++)
            scanf("%d%d",&Time[i],&val[i]);
        for(i=0;i<=m;i++){
            for(j=0;j<=l;j++){
                if(i==0) dp[i][j] = 0;
                else dp[i][j] = - INT_MAX;
            }
        }
        for(i=0;i<n;i++){
            for(j=m;j>=1;j--){
                for(k=l;k>=Time[i];k--){
                    dp[j][k] = max(dp[j][k],dp[j-1][k-Time[i]]+val[i]);
                }
            }
        }
        if(dp[m][l]<0) dp[m][l] = 0;
        printf("%d\n",dp[m][l]);
    }
    return 0;
}


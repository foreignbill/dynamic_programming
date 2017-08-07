#include <bits/stdc++.h> 
using namespace std;
int a[105][105],dp[105];
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)
        break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                 scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=m;j>=0;j--)
                for(int k=1;k<=j;k++)
                    dp[j]=max(dp[j],dp[j-k]+a[i][k]);
        printf("%d\n",dp[m]);
    }
    return 0;
}


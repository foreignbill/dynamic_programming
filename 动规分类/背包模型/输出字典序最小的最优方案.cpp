#include <bits/stdc++.h>

using namespace std;
const int maxn=1005;
struct node {
    int id,score,cost;
}a[101];
int vis[maxn][maxn],dp[maxn],id[maxn],S[maxn];
int main(){
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--){
        printf("Case #%d:\n",++cas);
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        memset(id,0x3f3f3f3f,sizeof id);
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=1; i<=n; i++)
            scanf("%d %d",&a[i].score,&a[i].cost),a[i].id=i;
        for(int i=1;i<=n;i++)
            for(int j=m;j>=a[i].cost;j--)
                if(dp[j]<dp[j-a[i].cost]+a[i].score||((dp[j]==dp[j-a[i].cost]+a[i].score)&&id[j]>id[j-a[i].cost]+a[i].id)){
                    dp[j]=dp[j-a[i].cost]+a[i].score;
                    id[j]=id[j-a[i].cost]+a[i].id;
                    vis[i][j]=1;
                }
        printf("%d ",dp[m]);
        int sum=0,top=0,j=m;
        for(int i=n; i>=1; i--)
            if(vis[i][j]) {
                sum+=a[i].cost;
                S[top++]=a[i].id;
                j-=a[i].cost;
            }
        printf("%d\n",sum);
        if(top>=1)
            printf("%d",S[top-1]);
        for(int i=top-2;i>=0;i--)
            printf(" %d",S[i]);
        if(top>=1) printf("\n");
    }
    return 0;
}

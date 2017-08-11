/*************************************************************************
    > File Name: 3001.cpp
    > Author: foreignbill
    > Mail: foreignbill@foxmail.com
    > Created Time: 2017年06月25日 星期日 14时09分45秒
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int g[12][12];
int bit[12]={1,3,9,27,81,243,729,2187,6561,19683,59049};
int f[66666][12];
int num[66666][12];

void init(){
    for(int i=0;i<bit[10];i++){
        int tmp = i;
        for(int j=0;j<10;j++){
            num[i][j]=tmp%3;
            tmp/=3;
        }
    }
}

int main(){
    init();
    int n,m,u,v,w;
    while(~scanf("%d%d",&n,&m)){
        memset(g,-1,sizeof g);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            if(g[u][v]==-1)
                g[u][v]=g[v][u]=w;
            else
                g[u][v]=g[v][u]=min(w,g[u][v]);
        }
        memset(f,63,sizeof f);
        for(int i=0;i<n;i++)
            f[bit[i]][i]=0;
        int flg,ans,next;
        int INF = f[0][0];
        ans = INF;
        for(int i=0;i<bit[n];i++){
            flg=1;
            for(int j=0;j<n;j++){
                if(num[i][j]==0)
                    flg=0;
                if(f[i][j]==INF)
                    continue;
                for(int l=0;l<n;l++){
                    if(l==j || num[i][l]>=2 || g[l][j]==-1)
                        continue;
                    next = i + bit[l];
                    f[next][l] = min(f[next][l] , f[i][j] + g[l][j]);
                }
            }
            if(flg){
                for(int j=0;j<n;j++)
                    ans = min(ans,f[i][j]);
            }
        }
        if(ans == INF)
            ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}

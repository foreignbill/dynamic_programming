#include <bits/stdc++.h>

using namespace std;

bool p[5005][5005];
int  q[5005][5005];
int ans[5005];

char s[5005];

int main(){
    gets(s);
    int len = strlen(s);
    memset(p,0,sizeof p);
    memset(q,0,sizeof q);
    memset(ans,0,sizeof ans);
    for(int i=0;i<len;i++)
        p[i][i] = 1;

    for(int t=1;t<len;t++)
        for(int i=0;i+t<len;i++)
            if((i+1>i+t-1||p[i+1][i+t-1]) && s[i] == s[i+t])
                p[i][i+t] = 1;

    for(int t=0;t<len;t++)
        for(int j=0;j+t<len;j++){
            if(!p[j][j+t]) continue;
            int mid;
            if(t % 2 == 0){
                mid = (j+j+t)/2 - 1;
            } else {
                mid = (j+j+t)/2;
            }
            if(mid<j) q[j][j+t] = 1;
            else q[j][j+t] = q[j][mid] + 1;
            ans[q[j][j+t]]++;
        }
    for(int i=len-1;i>=0;i--)
        ans[i] = ans[i] + ans[i+1];
    for(int i=1;i<len;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[len]);
    return 0;
}

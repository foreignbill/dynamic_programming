#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	int x,y,w;
}info[50005];

int dp[50005],tmp[50005];

bool cmp(node A,node B){
	return A.w<B.w;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&info[i].x,&info[i].y,&info[i].w);
	sort(info+1,info+1+m,cmp);
	info[m+1].w=INT_MAX;
	int last = 0;
	for(int i=1;i<=m;i++){
		if(info[i].w<info[i+1].w){
			for(int j=last+1;j<=i;j++)
				tmp[info[j].x]=dp[info[j].x],tmp[info[j].y]=dp[info[j].y];
			for(int j=last+1;j<=i;j++){
				dp[info[j].x] = max(dp[info[j].x],tmp[info[j].y]+1);
				dp[info[j].y] = max(dp[info[j].y],tmp[info[j].x]+1);
			}
			last = i;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++)
		ans = max(dp[i],ans);
	printf("%d\n",ans);
	return 0;
} 

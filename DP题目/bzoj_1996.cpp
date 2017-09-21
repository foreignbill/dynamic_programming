#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 19650827;
ll f[2005][2005][2];//0 left 1 right
ll h[2005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
		f[i][i][0]=f[i][i][1]=1;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			/*if(h[i]<h[i+1]) 
				f[i][j][0]+=f[i+1][j][0];
			if(i+1!=j)
				if(h[i]<h[j])
					f[i][j][0]+=f[i+1][j][1]; */
			f[i][j][0]=f[i+1][j][0]*(h[i]<h[i+1])+f[i+1][j][1]*(h[i]<h[j]);
			f[i][j][0]%=(mod*2);
			/*if(h[j]>h[i])
				f[i][j][1]+=f[i][j-1][0];
			if(i+1!=j)
				if(h[j]>h[j-1])
					f[i][j][1]+=f[i][j-1][1]; */
			f[i][j][1]=f[i][j-1][0]*(h[j]>h[i])+f[i][j-1][1]*(h[j]>h[j-1]);
			f[i][j][1]%=(mod*2);
		}
	ll res=f[1][n][0]+f[1][n][1];
	res/=2;
	res%=mod;
	printf("%lld\n",res);
	return 0;
}

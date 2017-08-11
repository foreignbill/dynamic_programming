#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
ll f[25][25][25];
ll t[25];
void init(){
	t[1]=1;
	for(int i=2;i<=15;i++)
		t[i]=t[i-1]*10; 
	memset(f,0,sizeof f);
	for(int i=0;i<=9;i++)
		f[1][i][i]=1;
	for(int i=2;i<=15;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++){
				for(int p=0;p<=9;p++)
					f[i][j][p] += f[i-1][k][p];
				f[i][k][k] += t[i-1]; 
			}
}
ll solve(ll n,int k){
	int base[25];
	int len = 0;
	ll tmpn = n;
	while(n){
		base[++len]=n%10;
		n /= 10;
	}
	ll res = 0;
	for(int i=len-1;i>0;i--)
		for(int j=1;j<=9;j++)
			res += f[i][j][k];
	for(int i=1;i<base[len];i++)
		res += f[len][i][k];
	if(len&&base[len]==k){
		res += (tmpn % t[len] + 1);
	}
	for(int l=len-1;l>0;l--){
		for(int i=0;i<base[l];i++)
			res += f[l][i][k];
		if(base[l]==k){
			res += (tmpn % t[l] + 1);
		}
	}
	return res;
}
int main(){
	init();
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll ans[10];
	for(int i=0;i<=9;i++)
		ans[i] = solve(b,i) - solve(a-1,i);
	for(int i=0;i<=9;i++)
		printf("%lld%c",ans[i]," \n"[i==9]);
	return 0;
} 

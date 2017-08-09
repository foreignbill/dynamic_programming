#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[111111];
int f[111111][2][2];

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		memset(f,0,sizeof(f));
		f[1][0][0] = a[1];
		f[1][1][1] = 0;
		for(int i=2;i<=n;i++){
			f[i][1][1] = f[i-1][0][0];
			f[i][0][0] = gcd(f[i-1][0][0] , a[i]);
			f[i][0][1] = max(gcd(f[i-1][1][1] , a[i]) , gcd(f[i-1][0][1] , a[i]));
		}
		int ans = max(f[n][1][1] , f[n][0][1]);
		cout<<ans<<endl;
	}
	return 0;
}

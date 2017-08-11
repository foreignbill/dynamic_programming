#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int f[15][15];

void init(){
	memset(f,0,sizeof f);
	for(int i=0;i<=9;i++) f[1][i]=1;
	for(int i=2;i<=10;i++)
	    for(int j=0;j<=9;j++)
	        for(int k=0;k<=9;k++)
	            if(abs(j-k)>=2)f[i][j]+=f[i-1][k];
}

int count(int n){
	if(n<=0) return 0;
	int ans = 0;
	int base[15];
	int len = 0;
	while(n){
		base[++len] = n%10;
		n /= 10;
	}
	for(int i=1;i<=base[len]-1;i++)
		ans += f[len][i];
	for(int i=len-1;i;i--)
		for(int j=1;j<=9;j++)
			ans += f[i][j];
	for(int i=len-1;i;i--){
		for(int j=0;j<base[i];j++)
			if(abs(base[i+1] - j) >= 2)
				ans += f[i][j];
		if(abs(base[i+1] - base[i]) < 2) break;
	}
	return ans;
}

int main(){
	init();
	int A,B;
	scanf("%d%d",&A,&B);
	int ans = count(B+1) - count(A);
	printf("%d\n",ans);
	return 0;
} 

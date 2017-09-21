#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int f[505][505];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i][i]);
	int res=0;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			for(int k=i;k<=j;k++)
				if(f[i][k]==f[k+1][j])
					f[i][j]=max(f[i][j],f[i][k]+1);
			if(f[i][j]>res) res=f[i][j];
		}
	printf("%d\n",res);
	return 0;
}
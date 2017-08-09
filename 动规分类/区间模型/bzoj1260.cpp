#include <bits/stdc++.h>
using namespace std;
int f[55][55];
char s[55];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=1;
	for(int l=1;l<n;l++)
		for(int i=1;i<=n;i++){
			int j=i+l;
			if(j>n)break;
			if(s[i]==s[j]){
				if(l==1)f[i][j]=1;
				else{
					f[i][j]=min(f[i+1][j],f[i][j-1]);
					f[i][j]=min(f[i][j],f[i+1][j-1]+1);
				}
			}
			else for(int k=i;k<j;k++)f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	printf("%d\n",f[1][n]);
	return 0;
}

for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
		if(a[i]>a[j])
			dp[i]=max(dp[i],max(1,dp[j]));

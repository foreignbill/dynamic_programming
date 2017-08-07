for(int i=1;i<=n;i++)
	for(int v=maxv;v>=cost[i];v--)
		dp[v] = min(dp[v],dp[v-cost[i]]+value[i]); 

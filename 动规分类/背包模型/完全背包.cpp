for(int i=1;i<=n;i++)
	for(int v=cost[i];v<=maxv;v++)
		dp[v] = min(dp[v],dp[v-cost[i]]+value[i]); 

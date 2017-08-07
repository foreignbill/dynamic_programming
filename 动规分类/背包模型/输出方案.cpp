void print_ans(int* dp,int s){
	for(int i=1;i<=n;i++){
		if(s>=cost[i] && dp[s]==dp[s-cost[i]]+value[i]){
			cout<<i;
			print_ans(dp,s-cost[i]);
			break;
		}
	}
}

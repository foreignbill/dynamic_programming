for(int i=1;i<=m;i++){
    if(p[i]*c[i]>=n){//容量大与V可以做完全背包 
        for(int j=p[i];j<=maxv;j++){
            dp[j]=max(dp[j-p[i]]+h[i],dp[j]);
        }
    }
    else{//二进制拆分做01背包 
        int k, ki;
        for(k = 0; ((1 << (k + 1)) - 1) < c[i]; ++k){
            ki = (1 << k);
            for(int j=maxv;j>=p[i]*ki;j--){
                dp[j] = max(dp[j - p[i] * ki] + h[i] * ki, dp[j]);
            }
        }
        ki = c[i] - ((1 << k) - 1);
        for(int j=maxv;j>=p[i]*ki;j--){
            dp[j] = max(dp[j - p[i] * ki] + h[i] * ki, dp[j]);
        }
    }
}

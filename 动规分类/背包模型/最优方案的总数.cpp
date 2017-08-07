for(int i=1;i<=N;i++)
    for(int v=c[i];v<=MAXV;v++){
        f[i][v]=max(f[i-1][v],f[i-1][v-c[i]]+w[i])
        g[i][v]=0;
        if(f[i][v]==f[i-1][v])
            g[i][v]+=g[i-1][v]; 
        if(f[i][v]==f[i-1][v-c[i]]+w[i])
            g[i][v]+=g[i-1][v-c[i]];
	}

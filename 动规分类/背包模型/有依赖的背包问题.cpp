//hdu 3449
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int dp[N][2];
void solve() {
    memset(dp, 0, sizeof(dp));
    int pair, box, cost, val;
    for (int num = 1; num <= n; num++) {
        scanf("%d%d", &box, &pair);

        //买了箱子
        for (int i = m; i >= box; i--)
            dp[i][1] = dp[i - box][0];

        //不买箱子
        for (int i = box - 1; i >= 0; i--)
            dp[i][1] = dp[i][0];

        for (int p = 0; p < pair; p++) {
            scanf("%d%d", &cost, &val);
            for (int i = m; i >= box + cost; i--) {
                dp[i][1] = max(dp[i][1], dp[i - cost][1] + val);
            }
        }
        //取最大值
        for (int i = 0; i <= m; i++)
            dp[i][0] = max( dp[i][0], dp[i][1]);
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(dp[i][0], ans);
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        solve();
    }
    return 0;
} 

/*
Q: 给的一个数组，求最大整数k，使得存在数组存在有效划分：[L1, R1], [L2, R2]...[Lk, Rk]，k个子数组互不重叠，且子数组的长度依次为：k, k-1, k-2, ...1，
并且子数组之和严格单调增，数组长度小于1e5。
A: 考虑最大可能答案
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5, M = 505;
LL dp[N][M];
LL pre[N];

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif

    int T, n;
    cin >> T;
    pre[0] = 0;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> pre[i];
        for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
        dp[n + 1][0] = INT_MAX;
        for (int i = 1; i < M; ++i) dp[n + 1][i] = 0;
        for (int i = n; i; --i) {
            dp[i][0] = dp[i + 1][0];
            for (int k = 1; k < M; ++k) {
                dp[i][k] = dp[i + 1][k];
                if (i + k - 1 <= n) {
                    LL s = pre[i + k - 1] - pre[i - 1];
                    if (s < dp[i + k][k - 1]) dp[i][k] = max(dp[i][k], s);
                }
            }
        }
        int ans = 0;
        while (dp[1][ans]) ++ans;
        cout << ans - 1 << endl;
    }   

    return 0;
}
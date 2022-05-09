/*
Q: 给定英雄数量n和最大血量x，每一回合每个英雄都会对其他存活英雄造成一点伤害，问有多少种方式使得有限回合下来
后无人生还？
A: 考虑如何构造状态能够有效处理最大血量这个限制。

*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 505, MOD = 998244353;
int f[N][N], c[N][N];


int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    memset(c, 0, sizeof(c));
    for (int i = 0; i < N; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    memset(f, 0, sizeof(f));

    int n, x;
    cin >> n >> x;
    f[n][0] = 1;
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < x; ++j) {
            LL t = 1, nj = min(x, j + i - 1);
            for (int ni = i; ni >= 0; --ni) {
                f[ni][nj] = (f[ni][nj] + 1ll * c[i][ni] * f[i][j] % MOD * t % MOD) % MOD;
                t = t * (nj - j) % MOD;
            }
        }
    }
    LL ans = 0;
    for (int i = x; i >= 0; --i) ans = (ans + f[0][i]) % MOD;
    cout << ans << endl;

    return 0;
}
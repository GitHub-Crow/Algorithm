#include <iostream>
using namespace std;
const int N = 6, M = 105, K = 25;
int f[M][1<<(N<<1)][K];
int n, m, k;

int loit(int v) {
    int b = 0;
    for ( ; v; v -= (v & (-v))) ++b;
    return b;
}

int main()
{
	freopen("data.txt", "r", stdin);
    cin >> n >> m >> k;
    f[0][0][0] = 1;
    int alls = (1 << (n << 1)), halfs = 1 << n;
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < alls; ++j) {
            int fs = j / halfs, ss = j % halfs;
            int sso = loit(ss);
            if (((fs >> 2) & ss) or (ss >> 2) & fs) continue ; // first state crash second state
            for (int zs = 0; zs < halfs; ++zs) {
                if ((zs >> 2 & fs) or (fs >> 2 & zs)) continue ; // zero state crash first state
                for (int o = sso; o <= k; ++o) {
                    f[i][j][o] = f[i][j][o] + f[i - 1][(zs << n) + fs][o - sso];
                }
            }
        }
    int ans = 0;
    for (int s = 0; s < alls; ++s) ans += f[m][s][k];
    return ans;
    
    return 0;
}
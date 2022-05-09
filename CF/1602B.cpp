#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e3 + 5;
int f[N][2];
int cnt[N];
typedef pair<pair<int, int>, int> P;

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, q, x, k, n, j;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> f[i][0];
        cin >> q;
        vector<P> qs;
        for (int i = 0; i < q; ++i) {
            cin >> x >> k;
            qs.push_back(make_pair(make_pair(k, x), i));
        }
        sort(qs.begin(), qs.end());
        vector<int> ans(q);
        int qi = 0, now = 0;
        bool isOk = false;
        for (int i = 0; !isOk; ++i) {
            isOk = true;
            while (qi < q && qs[qi].first.first == i) {
                k = qs[qi].first.first, x = qs[qi].first.second;
                j = qs[qi].second;
                ans[j] = f[x][now];
                ++qi;
            }
            int nxt = 1 - now;
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= n; ++i) cnt[f[i][now]]++;
            for (int i = 1; i <= n; ++i) {
                f[i][nxt] = cnt[f[i][now]];
                if (f[i][nxt] != f[i][now]) isOk = false;
            }
            now = nxt;
            // cout << n << "!: " << i << endl;
            // for (int o = 1; o <= n; ++o) cout << f[o][now] << ' ';
            // cout << endl;
        }
        while (qi < q) {
            k = qs[qi].first.first, x = qs[qi].first.second, j = qs[qi].second;
            j = qs[qi].second;
            ans[j] = f[x][now];
            ++qi;
        }
        for (auto & v : ans) cout << v << endl;
    }
    

    return 0;
}
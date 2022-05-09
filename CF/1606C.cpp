/*
Q：给定可使用的10的1到9次方中几个数，f(x)表示使用这几个数表示成x的个数，给定k，问满足f(y)>k的最小的y是多少？
A：考虑每种数字最多可以换算多少个
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, k, n;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int x = 1;
            while (a[i]--) x *= 10;
            a[i] = x;
        }
        LL ans = 0;
        ++k;
        for (int i = 0; i < n; ++i) {
            int res = k;
            if (i + 1 < n) res = min(res, a[i + 1] / a[i] - 1);
            k -= res;
            ans += 1ll * res * a[i];
        }
        cout << ans << endl;
    }
    

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int b[30];
int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, n, v;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; ++i) {
            cin >> v;
            for (int k = 0; k < 30; ++k) {
                if (v >> k & 1) ++b[k];
            }
        }
        int s = accumulate(b, b + 30, 0);
        if (s == 0) {
            for (int i = 1; i <= n; ++i) cout << i << ' ';
            cout << endl;
        }
        else {
            int g = 0;
            for (int i = 0; i < 30; ++i) g = __gcd(g, b[i]);
            for (int i = 1; i <= g; ++i) {
                if (g % i == 0) cout << i << ' ';
            }
            cout << endl;
        }
    }

    

    return 0;
}
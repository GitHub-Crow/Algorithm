#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 105;
int pres[N];

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    string os;
    cin >> os;
    string s;
    for (auto& v : os) {
        if (v != '0') s.push_back(v);
    }
    if (s.empty()) {
        cout << "YES\n";
        return 0;
    }
    n = s.size();
    memset(pres, 0, sizeof(pres));
    for (int k = 1; k <= n; ++k) {
        pres[k] = pres[k - 1] + s[k - 1] - '0';
    }
    for (int i = 1; i < n; ++i) {
        int s = pres[i];
        if (pres[n] % s) continue ;
        int j = i + 1;
        for (int t = (s << 1) ; j < n; ++j) {
            if (pres[j] > t) break ;
            else if (pres[j] == t) {
                t += s;
            }
        }
        if (j == n) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
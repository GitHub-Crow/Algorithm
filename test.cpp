#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e3 + 5;
struct Node {
    int p, s, v;
    double avg;
}nodes[N];
int n, R, a, b, w;

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    cin >> n >> R;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].v;
        nodes[i].s = 1;
        nodes[i].avg = nodes[i].v;
        ans += nodes[i].v;
    }
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        nodes[b].p = a;
    }
    for (int i = 1; i < n; ++i) {
        int k, j;
        for (k = 0, j = 1; j <= n; ++j) {
            if (j != R and ((!k) or nodes[j].avg > nodes[k].avg)) {
                k = j;
            }
        }
        nodes[k].avg = -1; // make node k invalid.
        int f = nodes[k].p;
        for (int o = 1; o <= n; ++o) {
            if (nodes[o].p == k) {
                nodes[o].p = f;
            }
        }
        ans += nodes[f].s * nodes[k].v;
        nodes[f].v += nodes[k].v;
        nodes[f].s += nodes[k].s;
        nodes[f].avg = 1.0 * nodes[f].v / nodes[f].s;
    }
    string s = "12345678912";
    cout << atoi(s.c_str()) << endl;
    cout << ans << endl;

    return 0;
}
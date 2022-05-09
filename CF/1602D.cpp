#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
#define LOCAL

const int N =3e5 + 5;
int a[N], b[N], dis[N], from[N];

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    dis[n] = 0;
    priority_queue<P, vector<P>, greater<P>> h;
    h.push(make_pair(dis[n], n));
    bool isOk = false;
    while (!h.empty() && !isOk) {
        auto t = h.top(); h.pop();
        int k = t.second;
        if (t.first != dis[k]) continue ;
        int sk = k + b[k], nv = dis[k] + 1, nk = sk;
        for (int i = 0; i <= a[sk]; ++i, --nk) {
            if (nk < 0) break ;
            if (dis[nk] > nv) {
                dis[nk] = nv;
                from[nk] = k;
                if (nk == 0) {
                    isOk = true;
                    break ;
                }
                h.push(make_pair(dis[nk], nk));
            }
        }
    }
    if (!isOk) cout << "-1\n";
    else {
        cout << dis[0] << endl;
        int now = 0;
        vector<int> steps;
        while (from[now]) {
            steps.push_back(now);
            now = from[now];
        }
        reverse(steps.begin(), steps.end());
        for (auto & v : steps) cout << v << ' ';
        cout << endl;
    }

    return 0;
}
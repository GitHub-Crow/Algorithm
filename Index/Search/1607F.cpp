/*
Q: 给定一个棋盘，上面的字母表示下一步的走向，有效路径要求不能越过边界且不能访问重复的位置，你可以从任意位置开始
出发，请问最长的有效路径是多长？
A: DFS如何判断后向边？
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 4e6 + 5;
int to[N];
int f[N];
bool ins[N];
int T, n, m;
int id(int x, int y) {
    return x * m + y;
}

void dfs(int x) {
    if (ins[x]) {
        int p = x;
        ins[x] = false;
        do {
            p = to[p];
            f[x]++;
        } while (p != x);
        p = to[x];
        while (p != x) {
            ins[p] = false;
            f[p] = f[x];
            p = to[p];
        }
        return ;
    }
    ins[x] = true;
    if (!~to[x]) f[x] = 1;
    else {
        if (!f[to[x]]) {
            dfs(to[x]);
            if (f[x]) return ;
        }
        f[x] = f[to[x]] + 1;
    }
    ins[x] = false;
}

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    
    cin >> T;
    while (T--) {
        cin >> n >> m;
        char d;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y) {
                int o = id(x, y);
                to[o] = -1;
                ins[o] = f[o] = 0;
                cin >> d;
                int nx = x, ny = y;
                if (d == 'L') --ny;
                if (d == 'R') ++ny;
                if (d == 'U') --nx;
                if (d == 'D') ++nx;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) to[o] = id(nx, ny);
            }
        int ans = 0;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y) {
                int o = id(x, y);
                if (!f[o]) {
                    dfs(o);
                    if (f[ans] < f[o]) ans = o;
                }
            }
        cout << ans / m + 1 << ' ' << ans % m + 1 << ' ' << f[ans] << endl;
    }
    

    return 0;
}
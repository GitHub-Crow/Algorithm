/*
Q: 有一只青蛙从n出发，需要跳到0，给定数组a表示最大跳跃距离，数组b表示每次跳跃后下滑的距离，也就从i-a[i]下滑至i-a[i]+b[i]，问
青蛙跳至0的最少跳跃次数。
A: 避免同一个位置被访问多次，只需关注跳到每个位置上的最少跳跃次数即可。

*/
#include <bits/stdc++.h>

using namespace std;
#define LOCAL
typedef long long LL;
typedef pair<int, int> P;

const int N =3e5 + 5, INF = 0x3f3f3f3f;
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
    queue<int> q;
    q.push(n);
    bool isOk = false;
    int minHeight = n;
    while (!q.empty() && !isOk) {
        auto k = q.front(); q.pop();
        int sk = k + b[k];
        for (int i = min(minHeight, sk) - 1; i >= sk - a[sk]; --i) {
            dis[i] = dis[k] + 1;
            q.push(i);
            from[i] = k;
            if (i == 0) {
                isOk = true;
                break ;
            }
        }
        minHeight = min(minHeight, sk - a[sk]); // make sure every position we only process once.
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
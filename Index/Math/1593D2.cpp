/*
Q: 给定一个长度为n的数组，请你找到最大的正整数k使得数组中的每个元素减去若干次k能够找到
至少n/2个相同的数，如果k可以无限大则输出-1.[n <= 40]
A: GCD
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

map<int, int> d;

void addFac(int v) {
    for (int k = 1; k * k <= v; ++k) {
        if (v % k == 0) {
            d[k]++;
            if (k * k != v) d[v / k]++;
        }
    }
}

int main(int argc, char * argv[]) 
{
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = -1;

        for (auto & v : a) {
            int same = 0;
            d.clear();
            for (auto & u : a) {
                if (u == v) {
                    ++same;
                }
                else if (u > v) {
                    addFac(u - v);
                }
            }
            if (same >= n / 2) {
                ans = -1;
                break ;
            }
            for (auto it = d.begin(); it != d.end(); ++it) {
                if (it->second + same >= n / 2) ans = max(ans, it->first);
            }
        }
        cout << ans << endl;
    }
    

    return 0;
}
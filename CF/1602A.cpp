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
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        auto it = min_element(s.begin(), s.end());
        cout << *it << ' ';
        s.erase(it);
        cout << s << endl;
    }

    return 0;
}
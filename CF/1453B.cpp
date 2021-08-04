#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int a[N], b[N];

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
		for (int i = 0; i < n; ++i) cin >> a[i];
		LL ans = 0;
		for (int i = 1; i < n; ++i) {
			b[i] = a[i] - a[i - 1];
			ans += abs(b[i]);
		}
		int mind = max(abs(b[1]), abs(b[n - 1]));
		for (int i = 1; i < n - 1; ++i) {
			mind = max(mind, min(b[i + 1], -b[i]) * 2);
			mind = max(mind, min(b[i], -b[i + 1]) * 2);
		}
		cout << ans - mind << endl;
	}
	

    return 0;
}
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
	cin >> T;
	int n, m, u;
	while (T--) {
		int rs = 0, bs = 0;
		int rms = 0, bms = 0;
		cin >> n;
		for (int k = 1; k <= n; ++k) {
			cin >> u;
			rs += u;
			rms = max(rms, rs);
		}
		cin >> m;
		for (int k = 1; k <= m; ++k) {
			cin >> u;
			bs += u;
			bms = max(bms, bs);
		}
		// cout << rms << ' ' << bms << endl;
		cout << rms + bms << endl;
	}

    return 0;
}
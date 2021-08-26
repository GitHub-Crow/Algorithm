#include <bits/stdc++.h>
#define LOCAL 
using namespace std;
typedef long long LL;

int n, k;
const int MOD = 1e9 + 7;

LL qpow(int e, int x) {
	LL c = e;
	LL r = 1;
	for (int k = x; k; k >>= 1) {
		if (k & 1) {
			r = r * c % MOD;
		}
		c = c * c % MOD;
	}
	return r;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		if (n & 1) {
			cout << qpow(qpow(2, n - 1) + 1, k) << endl;
		}
		else {
			if (k == 0) {
				cout << 1 << endl;
				continue ;
			}
			LL ans = 0, q = qpow(2, n - 1), cur = 1;
			for (int i = 1; i <= k; ++i) {
				ans = (ans + cur * qpow(2 * q, (k - i))) % MOD;
				cur = cur * (q - 1) % MOD;
			}
			ans = (ans + cur) % MOD;
			cout << ans << endl;
		}
	}
 

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int MOD = 9901;

LL pow_(LL p, LL e) {
	LL ans = 1;
	LL cur = p;
	for (int k = 0; k < 30; ++k) {
		if (e >> k & 1) ans = ans * cur % MOD;
		cur = cur * cur % MOD;
	}
	return ans;
}

LL gen(LL p, LL e) {
	if (e == 0) return 1;
	LL r;
	if (e & 1) r = (1 + pow_(p, (e + 1) / 2)) * gen(p, (e - 1) / 2);
	else r = (1 + pow_(p, e / 2)) * gen(p, e / 2 - 1) + pow_(p, e);
	return r % MOD;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int a, b;
	cin >> a >> b;
	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}
	LL ans = 1;
	for (LL k = 2; k <= a; ++k) {
		LL o = 0;
		while (a % k == 0) {
			a /= k;
			++o;
		}
		ans = ans * gen(k, o * b) % MOD;
	}
	cout << ans << endl;
    return 0;
} 
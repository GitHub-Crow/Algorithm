// 取小于等于n的三个数使得三个数的最小公倍数最大
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	if (n < 3) cout << n << endl;
	else {
		LL x = 1ll * n * (n - 1), ans = 1ll * (n - 1) * (n - 2) * (n - 3);

		for (LL k = 1; k <= n; ++k) {
			LL y = x * k / __gcd(x, k);
			ans = max(ans, y);
		}
		cout << ans << endl;
	}

    return 0;
}
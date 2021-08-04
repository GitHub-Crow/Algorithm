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
	int a, b, p;
	cin >> a >> b >> p;
	LL ans = 1, cur = a;
	for (int k = 0; k < 30; ++k) {
		if (b >> k & 1) {
			ans = ans * cur % p;
		}
		cur = cur * cur % p;
	}
	if (a) cout << ans % p << endl;
	else cout << 0 << endl;

    return 0;
}
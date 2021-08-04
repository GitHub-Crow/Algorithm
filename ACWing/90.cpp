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
	LL a, b, p;
	cin >> a >> b >> p;
	LL ans = 0, cur = a;
	for (LL k = 0; (1 << k) <= b; ++k) {
		if (b >> k & 1) ans = (ans + cur) % p;
		cur = (cur << 1) % p;
	}
	cout << ans << endl;

    return 0;
}
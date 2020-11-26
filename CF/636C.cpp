#include <iostream>
#include <limits>

using namespace std;
typedef long long LL;

#define LOCAL


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, x;
	cin >> T;
	while (T--) {
		cin >> n;
		bool isNeg = false;
		LL ans = 0;
		int me = 0;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x < 0) {
				if (isNeg) me = max(me, x);
				else {
					ans += me;
					me = x;
					isNeg = true;
				}
			} else {
				if (!isNeg) me = max(me, x);
				else {
					ans += me;
					me = x;
					isNeg = false;
				}
			}
		}
		ans += me;
		cout << ans << endl;
	}
	

    return 0;
}
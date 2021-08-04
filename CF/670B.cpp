#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int a[N];

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
		int maxE = -1;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			maxE = max(maxE, a[i]);
		}
		sort(a, a + n, [](int & lhs, int & rhs) {return abs(lhs) > abs(rhs);});
		if (maxE < 0) {
			LL c = 1;
			for (int i = 0; i < 5; ++i) c *= a[n - i - 1];
			cout << c << endl;
			continue ;
		}
		LL ans = 1ll * a[0] * a[1] * a[2] * a[3] * a[4];
		for (int i = 5; i < n; i++) {
			for (int j = 0; j < 5; ++j) {
				LL t = a[i];
				for (int k = 0; k < 5; ++k) {
					if (k != j) t *= a[k];
				}
				ans = max(ans, t);
			}
		}
		cout << ans << endl;
	}
	

    return 0;
}
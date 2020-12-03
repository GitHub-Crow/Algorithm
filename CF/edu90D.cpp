#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 2e5 + 5;
int a[N];

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
		LL s = 0;
		vector<LL> v(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			v[i + 1] = v[i];
			if (i & 1) v[i + 1] += a[i];
			else v[i + 1] -= a[i];
			if (!(i & 1)) s += a[i];
		}
		const LL INF = 1e18;
		LL vme = INF, vmo = INF, ans = s;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				ans = max(ans, s + v[i + 1] - vme);
				vmo = min(vmo, v[i]);
			}
			else {
				ans = max(ans, s + v[i + 1] - vmo);
				vme = min(vme, v[i]);
			}
		}
		cout << ans << endl;
	}

    return 0;
}
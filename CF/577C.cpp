#include <iostream>
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

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int m = n / 2;
	sort(a, a + n);
	LL s = 0, ans = 0;
	for (int i = m; i < n; ++i) {
		LL x = 1ll * (i - m) * a[i];
		if (x - s > k) {
			ans = (s + k) / (i - m);
			break ;
		}
		s += a[i];
	}
	if (!ans) ans = (s + k) / (n - m);
	cout << ans << endl;

    return 0;
}
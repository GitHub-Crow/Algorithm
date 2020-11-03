#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 3e3 + 5;
int a[N];
int f[N];
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> a[i];

	sort(a, a + n);
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i - 1];
	if (p[n] <= m) cout << 1 << endl;
	else {
		memset(f, 0, sizeof(f));
		int ans = 0;
		f[0] = 1;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = max(m - a[i] - p[i] + 1, 0); j <= m - p[i]; ++j) ans += f[j];
			for (int k = m; k >= a[i]; --k) f[k] += f[k - a[i]];	
		}
		cout << ans << endl;
	}
    return 0;
}
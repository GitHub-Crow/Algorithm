#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 3e5 + 5;
int a[N], g[N];
int T, n;

int f(int x) {
	if (x <= 0 || x >= n - 1) return 0;
	return (((a[x] > a[x - 1] && a[x] > a[x + 1]) ||
			 (a[x] < a[x - 1] && a[x] < a[x + 1])) ? 
			 1 : 0);
} 

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	
	cin >> T;
	while (T--) {
		cin >> n;
		for (int k = 0; k < n; ++k) cin >> a[k];
		int s = 0;
		for (int k = 1; k < n - 1; ++k) {
			g[k] = f(k);
			s += g[k];
		}
		int ans = s;
		for (int k = 1; k < n - 1; ++k) {
			int tmp = a[k];
			a[k] = a[k - 1];
			ans = min(ans, s - g[k - 1] - g[k] - g[k + 1] + 
					f(k - 1) + f(k) + f(k + 1));
			a[k] = a[k + 1];
			ans = min(ans, s - g[k - 1] - g[k] - g[k + 1] + 
					f(k - 1) + f(k) + f(k + 1));
			a[k] = tmp;
		}
		cout << ans << endl;
	}
	

    return 0;
}
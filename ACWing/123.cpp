#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 10005;
int x[N], y[N], o[N];
int n;

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	int ans = 0;
	sort(y, y + n);
	for (int i = 0, j = n - 1; i < j; ++i, --j) ans += y[j] - y[i];
	sort(x, x + n);
	for (int i = 0; i < n; ++i) o[i] = x[i] - i;
	sort(o, o + n);
	int t = (o[n/2] + o[(n-1)/2]) / 2;
	for (int i = 0; i < n; ++i) ans += abs(x[i] - i - t);
	cout << ans << endl;
    return 0;
}
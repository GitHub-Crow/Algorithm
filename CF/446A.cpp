#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int a[N], le[N], ri[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	le[0] = 1, ri[n - 1] = 1;
	for (int k = 1; k < n; ++k) if (a[k] > a[k - 1]) le[k] = le[k - 1] + 1; else le[k] = 1;
	for (int k = n - 2; k >= 0; --k) if (a[k] < a[k + 1]) ri[k] = ri[k + 1] + 1; else ri[k] = 1;
	int ans = max(*max_element(le, le + n), *max_element(ri, ri + n)) + 1;
	ans = min(n, ans);
	for (int k = 1; k < n - 1; ++k) {
		if (a[k - 1] < a[k + 1] - 1) ans = max(ans, le[k - 1] + ri[k + 1] + 1);
	}
	cout << ans << endl;

    return 0;
}
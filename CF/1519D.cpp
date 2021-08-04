#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 5e3 + 5;
int a[N], b[N];
LL p[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	p[0] = 0;
	for (int i = 0; i < n; ++i) p[i + 1] = p[i] + 1ll * a[i] * b[i];

	LL ans = p[n];
	for (int center = 0; center < n; ++center) {
		LL cur = 0;
		for (int iL = center, iR = center + 1; iL >= 0 and iR < n; --iL, ++iR) {
			cur += 1ll * a[iL] * b[iR] + 1ll * a[iR] * b[iL];
			ans = max(ans, cur + p[iL] + p[n] - p[iR + 1]);
		}
		cur = 1ll * a[center] * b[center];
		for (int iL = center - 1, iR = center + 1; iL >= 0 and iR < n; --iL, ++iR) {
			cur += 1ll * a[iL] * b[iR] + 1ll * a[iR] * b[iL];
			ans = max(ans, cur + p[iL] + p[n] - p[iR + 1]);
		}
	}
	cout << ans << endl;

    return 0;
} 
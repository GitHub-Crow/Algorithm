#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 1e5 + 5;
const LL INF = 1e18;
int a[N];
void mul(LL& cur, LL q) {
	if (INF / cur < q) cur = INF;
	else cur *= q;
}

void add(LL& cur, LL cost) {
	if (INF - cur < cost) cur = INF;
	else cur += cost;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	LL ans = INF;
	LL cur = 1, cost = 0;
	for (int q = 1; ; ++q) {
		cur = 1, cost = 0;
		for (int i = 0; i < n; ++i) {
			add(cost, abs(cur - a[i]));
			mul(cur, q);
		}
		if (cost == INF || cur / q > ans + a[n - 1]) break ;
		ans = min(ans, cost);
	}
	cout << ans << endl;

    return 0;
}
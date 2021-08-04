#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e6 + 5;
LL a[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	LL s = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), s += a[i];
	s /= n;
	a[0] = 0;
	for (int i = 1; i <= n; ++i) a[i] = a[i - 1] - s + a[i];
	sort(a + 1, a + n + 1);
	LL ans = 0;
	for (int i = 1, j = n; i < j; ++i, --j) ans += a[j] - a[i];
	printf("%lld\n", ans);
	

    return 0;
}
#include <bits/stdc++.h>

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
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		LL tot = 0;
		for (int i = 0; i < n; ++i) tot += a[i];
		LL ans = 0;
		for (int k = 0; k < n; ++k) {
			LL tmp = (n - 1) * a[n - 1]tot - a[n - 1] - a[0]
		}
	}
	

    return 0;
}
#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL
int N = 2e5 + 5;
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
		LL bo = 0, be = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (i & 1) bo += a[i];
			else be += a[i];
		}
		LL ans = be, cur = 0;
		for (int i = 0; i < n; ++i) {
			if (i & 1) bo -= a[i];
			else {
				cur += a[i];
				be -= a[i];
			}
			ans = max(ans, cur + max(be, bo));
		}
	}

    return 0;
}
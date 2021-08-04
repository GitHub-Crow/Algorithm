#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, th;
const int N = 2e5 + 5;
int h[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	bool f;
	cin >> T;

	while (T--) {
		f = true;
		cin >> n >> th;
		for (int k = 0; k < n; ++k) cin >> h[k];
		int low = h[0], high = low + th;
		for (int k = 1; k < n; ++k) {
			int nlow = h[k], nhigh = h[k] + 2*th - 1;
			if (k == n - 1) nhigh = h[k] + th;
			if (nlow >= high || nhigh <= low) {
				f = false;
				break ;
			}
			low = max(nlow, low - th + 1);
			high = min(nhigh, high + th - 1);
			// printf("[%d, %d]\n", low, high);
		}
		cout << (f ? "YES" : "NO") << endl;
	}

    return 0;
}
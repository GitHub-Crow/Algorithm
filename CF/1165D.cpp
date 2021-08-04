#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



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
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i];
		sort(arr.begin(), arr.end());
		LL r = 1ll * arr[0] * arr[n - 1];
		for (int iL = 0, iR = n - 1; iL <= iR; ++iL, --iR) {
			if (1ll * arr[iL] * arr[iR] != r) {
				r = -1;
				break ;
			}
		}
		if (r != -1) {
			int idx = 0;
			for (LL k = 2; k * k <= r; ++k) {
				if (r % k == 0) {
					if (idx < n and arr[idx] == k) ++idx;
					else {
						r = -1;
						break ;
					}
				}
			}
		}
		cout << r << endl;
	}
	

    return 0;
}
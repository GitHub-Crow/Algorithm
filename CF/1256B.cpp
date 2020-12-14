#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int a[105];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> pos(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		for (int i = 1, w = 0; i < n; ) {
			for (int k = pos[i] - 1; k >= i && k >= w; --k) swap(a[k], a[k + 1]);

			w = max(w, pos[i]);
			while (i < n && pos[i] <= w) ++i;
			// cout << i << ' ' << j << endl;
		}
		for (int i = 1; i < n; ++i) cout << a[i] << ' ';
		cout << a[n] << endl;
	}	

    return 0;
}
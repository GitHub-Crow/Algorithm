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
		bool ans = true;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		if (a[0] < 0) ans = false;
		if (ans) {
			cout << "YES\n";
			cout << 101 << endl; 
			for (int k = 0; k <= 100; ++k) cout << k << ' ';
			cout << endl;
		}
		else {
			cout << "NO\n";
		}
	}
	

    return 0;
}
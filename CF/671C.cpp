#include <iostream>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T, n, x;
	cin >> T;
	while (T--) {
		cin >> n >> x;
		int u = 0, s = 0;
		bool f = true, g = false;
		for (int i = 0; i < n; ++i) {
			cin >> u;
			s += u;
			if (u != x) f = false;
			else g = true;
		}
		int ans = 0;
		if (f) ans = 0;
		else if (s == x * n || g) ans = 1;
		else ans = 2;
		cout << ans << endl;
	}
	

    return 0;
}
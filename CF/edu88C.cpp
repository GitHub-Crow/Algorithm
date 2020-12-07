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
	int T, h, c, t;
	cin >> T;
	while (T--) {
		cin >> h >> c >> t;
		double x = 1.0 * (h + c) / 2;
		if (t <= x) cout << "2\n";
		else {
			int k = (h - t) / (2 * t - h - c);
			LL left = abs(1ll * h * (k + 1) + 1ll * c * k - 1ll * (2 * k + 1) * t);
			++k;
			LL right = abs(1ll * h * (k + 1) + 1ll * c * k - 1ll * (2 * k + 1) * t);
			if ((2 * k + 1) * left <= (2 * k - 1) * right) cout << 2 * k - 1 << endl;
			else cout << 2 * k + 1 << endl;
		}	
		
	}
	

    return 0;
} 
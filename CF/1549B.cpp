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
		int ans = 0;
		string e, c;
		cin >> n;
		cin >> e >> c;
		for (int k = 0; k < n; ++k) {
			if (c[k] == '0') continue ;
			if (k > 0 and e[k - 1] == '1') {
				++ans;
				e[k - 1] = '2';
				continue ;
			}
			if (e[k] == '0') {
				++ans;
				continue ;
			}
			if (k < n - 1 and e[k + 1] == '1') {
				++ans;
				e[k + 1] = '2';
				continue ;
			}

		}
		cout << ans << endl;
	}
 

    return 0;
}
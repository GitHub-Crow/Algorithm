#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		string ans(n, 'a');
		for (int i = 2; i <= n; ++i) {
			LL len = 1ll * i * (i - 1) / 2;
			if (len < k) continue ;
			else {
				k -= 1ll * (i - 1) * (i - 2) / 2;
				ans[i - 1] = 'b';
				ans[k - 1] = 'b';
				break;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	

    return 0;
}
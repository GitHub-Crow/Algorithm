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
	int T;
	cin >> T;
	LL n;
	while (T--) {
		cin >> n;
		vector<int> ep;
		int pos2 = -1;
		while (n) {
			int e = n % 3;
			ep.push_back(e);
			if (e == 2) pos2 = ep.size() - 1;
			n /= 3;
		}
		ep.push_back(0);
		if (pos2 != -1) {
			int pos0 = find(ep.begin() + pos2, ep.end(), 0) - ep.begin();
			ep[pos0] = 1;
			for (int k = 0; k < pos0; ++k) ep[k] = 0;
		}
		LL ans = 0, pw = 1;;
		for (auto & e : ep) {
			ans += e * pw;
			pw *= 3;
		}
		cout << ans << endl;
	}
	

    return 0;
}
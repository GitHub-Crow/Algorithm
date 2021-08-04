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
	string s;
	while (T--) {
		cin >> n >> s;
		vector<int> dc(n + 1), kc(n + 1);
		for (int k = 0; k < n; ++k) {
			dc[k + 1] = dc[k];
			kc[k + 1] = kc[k];
			if (s[k] == 'D') ++dc[k + 1];
			else ++kc[k + 1];
		}
		map<pair<int, int>, int> c;
		for (int k = 1; k <= n; ++k) {
			int dce = dc[k], kce = kc[k];
			int egcd = __gcd(dce, kce);
			if (egcd) {
				dce /= egcd; kce /= egcd;
			}
			else {
				if (dce) dce = 1;
				if (kce) kce = 1;

			}
			auto key = make_pair(dce, kce);
			cout << c[key] + 1 << ' ';
			c[key]++;
		}
		cout << endl;
	}
	

    return 0;
}
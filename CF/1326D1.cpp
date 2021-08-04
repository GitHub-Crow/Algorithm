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
	string s;
	while (T--) {
		cin >> s;
		int n = s.size();
		int i = 0, j = n - 1;
		while (i < j and s[i] == s[j]) {
			++i;
			--j;
		}
		string ret;
		ret = s.substr(0, i) + s.substr(j + 1, n - j - 1);
		for (int k = j; i <= k;--k) {
			bool f = true;
			for (int u = i, v = k; u < v; ++u, --v) 
				if (s[u] != s[v]) {
					f = false;
					break;
				}
			if (f) {
				string tmp = s.substr(0, k + 1) + s.substr(j + 1, n - j - 1);
				if (tmp.size() > ret.size()) ret = tmp;
				break ;
			}
		}
		for (int k = i; k <= j; ++k) {
			bool f = true;
			for (int u = j, v = k; u > v; --u, ++v) 
				if (s[u] != s[v]) {
					f = false;
					break;
				}
			if (f) {
				string tmp = s.substr(0, i) + s.substr(k, n - k);
				if (tmp.size() > ret.size()) ret = tmp;
				break ;
			}
		}
		cout << ret << endl;
	}
	

    return 0;
}
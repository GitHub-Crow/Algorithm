/*
Q: 给定数组b，问是否存在数组a，使得对于任意bi，数组a的前缀a1,a2,....a(2*i - 1)的中位数等于bi。
A: 考虑在b(i)已经成立的情况下，b(i + 1)成立的条件。
*/
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
		vector<int> b(n);
		for (int i = 0; i < n; ++i) cin >> b[i];
		set<int> pref;
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			int prv = b[i - 1];
			pref.insert(prv);
			if (b[i] > prv) {
				auto it = pref.upper_bound(prv);
				if (it != pref.end() and *it < b[i]) {
					ok = false;
					break ;
				}
			}
			if (b[i] < prv) {
				auto it = pref.lower_bound(prv);
				if (it != pref.begin() and *(--it) > b[i]) {
					ok = false;
					break ;
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	

    return 0;
}
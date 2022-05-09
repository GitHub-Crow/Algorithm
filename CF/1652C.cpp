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
	string s;
	cin >> T;
	while (T--) {
		cin >> n >> s;
		int m = n / 2;
		bool isOk = false;
		for (int k = 0; k < n and (!isOk); ++k) {
			if (s[k] == '0') {
				if (k < m) {
					cout << k + 1 << ' ' << n << ' ' << k + 2 << ' ' << n << endl;
					isOk = true;
				}
				else {
					cout << 1 << ' ' << k + 1 << ' ' << 1 << ' ' << k << endl;
					isOk = true;
				}
			}
		}
		if (!isOk) cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
	}

	

    return 0;
}
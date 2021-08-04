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
		if (n == 1) cout << "9\n";
		else if (n == 2) cout << "98\n";
		else {
			string s(n, '0');
			s[0] = '9';
			int w = 8;
			for (int k = 1; k < n; ++k) {
				s[k] = '0' + w;
				++w;
				if (w > 9) w = 0;
			}
			cout << s << endl;
		}

	}

	

    return 0;
}
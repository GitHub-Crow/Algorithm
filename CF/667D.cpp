#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	while (T--) {
		LL n, s;
		cin >> n >> s;
		string d = to_string(n);
		LL ans;
		int m = d.size(), cur = 0, i = 0;
		for (int i = 0; i < m; ++i) cur += d[i] - '0';
		if (cur <= s) cout << "0\n";
		else {
			LL res = 0;
			i = 0, cur = 0;
			for (; i < m; ++i) {
				cur += d[i] - '0';
				if (cur >= s) break;
			}
			for (int j = i; j < m; ++j) 
				res = res * 10 + d[j] - '0';                        		
			LL ret = pow(10ll, (LL)(m - i));
			cout << ret - res << endl;
		}
	}

    return 0;
}
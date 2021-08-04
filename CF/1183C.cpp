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
	int T, n, k, a, b;
	cin >> T;
	while (T--) {
		cin >> n >> k >> a >> b;
		int iL = -1, iR = k;
		while (iL < iR) {
			int iM = (iL + iR + 1) / 2;
			bool f = 1ll * iM * a + 1ll * b * (k - iM) < n;
			if (f) iL = iM;
			else iR = iM - 1;
		}
		cout << iL << endl;
	}
    return 0;
}
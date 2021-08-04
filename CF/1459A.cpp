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
	string a, b;
	while (T--) {
		cin >> n >> a >> b;
		int u = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > b[i]) ++u;
			else if (a[i] < b[i]) --u;
		}
		if (u > 0) cout << "RED\n";
		else if (u < 0) cout << "BLUE\n";
		else cout << "EQUAL\n";
	}
	

    return 0;
}
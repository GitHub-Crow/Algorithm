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

	int T, r, b, d;
	cin >> T;
	while (T--) {
		cin >> r >> b >> d;
		LL minE = min(r, b), maxE = max(r, b);
		if (minE * (d + 1) < maxE) cout << "NO\n";
		else cout << "YES\n";
	}

    return 0;
}
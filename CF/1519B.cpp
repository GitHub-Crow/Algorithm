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
	int T, n, m, k;
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		if (n * m - 1 != k) cout << "NO\n";
		else cout << "YES\n";
	}
 

    return 0;
}
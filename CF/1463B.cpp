#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 55;
int a[N];


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
		for (int i = 0; i < n; ++i) cin >> a[i];
		LL so = 0, se = 0;
		for (int k = 0; k < n; ++k) if (k & 1) so += a[k]; else se += a[k];
		if (so < se) for (int k = 0; k < n; ++k) if (k & 1) cout << 1 << ' '; else cout << a[k] << ' ';
		else for (int k = 0; k < n; ++k) if (k & 1) cout << a[k] << ' '; else cout << 1 << ' ';
		cout << endl;
	}	

    return 0;
}
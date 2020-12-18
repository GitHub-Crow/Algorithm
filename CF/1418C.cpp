#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
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
		for (int i = 1; i <= n; ++i) cin >> a[i];
		vector<int> f0(n + 1, n), f1(n  + 1, n);
		f0[0] = 0; f1[1] = a[1];
		for (int k = 2; k <= n; ++k) {
			f1[k] = min(f0[k - 2] + a[k - 1] + a[k], f0[k - 1] + a[k]);
			f0[k] = min(f1[k - 2], f1[k - 1]);
		}
		cout << min(f0[n], f1[n]) << endl;

	}	

    return 0;
}
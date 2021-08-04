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


	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector<int> f(n);
	f[0] = 1;
	int ans = 0;
	for (int k = 1; k < n; ++k) {
		if (a[k] > a[k - 1]) 
			f[k] = f[k - 1] + 1; 
		else 
			f[k] = 1;
		ans = max(ans, f[k]);
	}
	vector<int> b(n);
	b[n - 1] = 1;
	for (int k = n - 2; k >= 0; --k) {
		if (a[k] < a[k + 1])
			b[k] = b[k + 1] + 1;
		else
			b[k] = 1;
	}
	for (int k = 1; k < n - 1; ++k) {
		if (a[k + 1] > a[k - 1]) ans = max(ans, f[k - 1] + b[k + 1]);
	}

    return 0;
}
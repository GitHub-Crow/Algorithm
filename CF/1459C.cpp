/*
Q: 对于数组A和数组B, 求对于对于任意bj的GCD(a1+bj, a2+bj, a3+bj, ..., an+bj).
A: GCD(x, y, z, ..) = GCD(x, y-x, z-x, ...).

*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
LL a[N], b[N];
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	LL g = 0;
	for (int i = 1; i < n; ++i) g = __gcd(abs(a[i] - a[0]), g);
	for (int i = 0; i < m; ++i) cout << __gcd(a[0] + b[i], g) << ' ';
	cout << endl;

    return 0;
}
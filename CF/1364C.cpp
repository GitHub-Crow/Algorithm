/*
Q: 定义MEX(S)为不在集合S内的最小非负正整数，输出数组b使得b[i]=MEX({a[0],a[1],...a[i]})。
A: 对于a[i-1]!=a[i]，则b[i]=a[i-1]。
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e5 + 5;
int a[N], ans[N], exc[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, v;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(exc, 0, sizeof(exc));
	memset(ans, -1, sizeof(ans));
	for (int k = 2; k <= n; ++k) {
		if (a[k] != a[k - 1]) {
			ans[k] = a[k - 1];
			exc[a[k - 1]] = 1;
		}
	}
	exc[a[n]] = 1;
	int m = 0;
	for (int k = 1; k <= n; ++k) {
		if (ans[k] != -1) continue ;
		while (exc[m]) ++m;
		ans[k] = m;
		exc[m] = 1;
	}
	for (int k = 1; k <= n; ++k) cout << ans[k] << ' ';
	cout << endl;
    return 0;
}
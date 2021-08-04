/*
Q: 给定一个长度为n的数组a，其中ai在[1, k]范围内，你可以使用[1, k]中的元素来替代ai，问至少需要多少次替代操作才能
使得对于在[1, n/2]内的任意下标i满足a[i] + a[n - i] == x
A: 枚举x，然后计算存在多少组一次替代、两次替代
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 2e5 + 5;
int a[N];
int b[2 * N];
int c[2 * N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		for (int i = 0; i < n; ++i)  cin >> a[i];

		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n / 2; ++i) {
			int u = a[i], v = a[n - i - 1];
			c[u + v]++;
			b[min(u, v) + 1]++;
			b[max(u, v) + k + 1]--;
		}
		int ans = 2 * n, prefx = 0;
		for (int x = 1; x <= 2 * k; ++x) {
			prefx += b[x];
			ans = min(ans, n - prefx - c[x]);
		}
		cout << ans << endl;
	}
	

    return 0;
}
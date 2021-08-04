/*
Q: 给定长度为n的数组，从中提取k段长度为m的子区间，且各个子区间不能相交
求子区间之和最大是多少？
A: 线性动态规划、单调队列优化
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 5e3 + 5;
int a[N];
LL f[N];
LL p[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; ++i) cin >> a[i];
	p[0] = 0;
	for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i];
	f[0] = 0;
	deque<int> que;
	que.push_back(0);
	for (int j = 1; j <= k; ++j) {
		for (int i = n; i; --i) {
			while (!que.empty() && que.front() + m > i) que.pop_front();
			if (!que.empty()) {
				auto t = que.front();
				if (t + m <= i) f[i] = f[t] + p[i] - p[i - m];
			}
			else 
				f[i] = -1;
		}
		que.clear();
		for (int i = n; i >= 0; --i) {
			while (!que.empty() && f[que.back()] < f[i]) que.pop_back();
			que.push_back(i);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
	cout << ans << endl;

    return 0;
}
// https://ac.nowcoder.com/acm/contest/8282/C
#include <iostream>
using namespace std;
typedef long long LL;
#define LOCAL

const int N = 1e6 + 5;
int a[N], st[N];
/*
题意：给定数组a，可以将每一个数由相邻两个数的平均数来代替，无限制操作下可得到的数组和最小是多少
首先可以想到的是，最终得到的最优数列两个数字之差会越来越小，因为如果a[i + 1] - a[i] > a[i] - a[i - 1]，说明
a[i]可以进行替换。并且最优解一定是由多个等差数列串联而成。
这里维护一个队列st，st中每个点都是每个等差数列的首尾项的下标，一个区间能通过上述操作变成等差数列的条件就是区间内的
元素均小于对应下标下的等差数列元素
*/

// 检查斜率u-w < u-v，即在区间[u, w]之间形成等差数列B，且首项为a[u]、末项为a[w]，a[v] > B[v]
bool check(int u, int v, int w) {
	return 1ll * (a[w] - a[u]) * (v - u) < 1ll * (a[v] - a[u]) * (w - u);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int top = 0;
	for (int i = 0; i < n; ++i) {
		while (top > 1 && check(st[top - 2], st[top - 1], i)) --top;
		st[top++] = i;
	}
	double ans = 0;
	for (int i = 1; i < top; ++i) {
		ans += 1.0 * (a[st[i]] + a[st[i - 1]]) * (st[i] - st[i - 1] + 1) / 2; 
	}
	// 首尾项重复计算了一次，需要减去
	for (int i = 1; i < top - 1; ++i)
		ans -= a[st[i]];
	printf("%.10f\n", ans);

    return 0;
}
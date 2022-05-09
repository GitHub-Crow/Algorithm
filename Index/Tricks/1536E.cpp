/*
Q: 给定一个二维grid，一个cell为0或者空，空cell可以写入非负数，满足以下两种条件：
1.如果是正数则需要满足至少有一个相邻cell的值小于该正数；
2.相邻cell的差值绝对值最大为1；
问有多少种填入方式？
A: 假定一些cell为0，其他的cell为正数，那么有且只有一种方式，cell中填写数值为距离最近0的距离。
*/
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
	const int MOD = 1e9 + 7;
	int T, n, m;
	char c;
	cin >> T;
	while (T--) {
		LL ans = 1;
		bool h = false;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cin >> c;
				if (c != '#') {
					h = true;
				}
				else {
					ans = (ans << 1) % MOD;
				}
			}
		if (not h) --ans;
		cout << ans << endl;
	}

    return 0;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++dfsNum;
	st.push(u);
	for (int k = h[u]; k ; k = next[k]) {
		int v = to[k];
		if (!dfn[v]) {
			tarjan(v);
			if (low[v] >= dfn[u]) ++bridge[u];
			low[u] = min(low[u], low[v]);
		}
		else {
			low[u] = min(low[u], dfn[v]);
		}
	}
	++bridge[u];
	if (low[u] == dfn[u]) {
		while (not st.empty() and st.top() != dfn[u]) {
			branch[u].push_back(st.top()); st.pop();
		}
		st.push_back(u);
	}
}  
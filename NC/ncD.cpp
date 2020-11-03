// https://ac.nowcoder.com/acm/contest/7501/D
// 判断双向图中删除每个点后所形成的强连通量的个数
#include <iostream>
#include <cstring>

typedef long long LL;
#define LOCAL

const int N = 3e5 + 5;
int h[N], to[N << 1], next[N << 1];
int dfn[N], low[N], bridge[N];
int idx = 0, dfsIter = 1;

// dfn[n]表示节点n在dfs中的时间戳
// low[n]表示以节点n为根节点的dfs子树中最小的时间戳

void tarjan(int u) {
	low[u] = dfn[u] = dfsIter++;
	for (int k = h[u]; k; k = next[k]) {
		int v = to[k];
		if (!dfn[v]) {
			tarjan(v);
			// 如果以v为根节点的子树中没有节点比u更先遍历到, 说明边u-v是桥
			if (dfn[u] <= low[v]) bridge[u] ++;
			low[u] = std::min(low[u], low[v]);
		} else {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	++ bridge[u];
	// 包括与父节点组成的桥边
}

// 容量不确定且数据较大时利用链表表示
// 建立链表元素：填充元素; 标记子节点; 变更头节点; 
void add(int u, int v) {
	to[idx] = v, next[idx] = h[u], h[u] = idx++;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int m, n;
	std::cin >> n >> m;
	idx = 1;
	// 存数据的列表下标需要从1开始
	std::memset(h, 0, sizeof(h));
	std::memset(to, 0, sizeof(to));
	std::memset(next, 0, sizeof(next));
	std::memset(dfn, 0, sizeof(dfn));
	std::memset(low, 0, sizeof(low));
	std::memset(bridge, 0, sizeof(bridge));
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		add(u, v);
		add(v, u);

	}


	dfsIter = 1;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) {
			-- bridge[i];
			// 根节点无父节点
			++cnt;
			tarjan(i);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		std::cout << cnt - 1 + bridge[i] << ' ';
	}

    return 0;
}
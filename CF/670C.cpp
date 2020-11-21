/*
树的重心：删除某节点，使得剩下的连通分量中最多节点数尽可能少，其中删除重心能得到最少
题意：树中可能存在多个重心，请删除一条边并增加一条边使得树只存在一个重心。
思考：树中最多有两个重心；且两个重心必定有一条边相连；
例如：BlockOne-A-B-BlockTwo，其中A和B是重心，且BlockOne-A总计n/2个节点
Solution：删掉BlockOne的一条叶节点的边，然后将其与B相连。
*/
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
vector<int> g[N];
int size[N], fa[N]; // size表示子树的节点个数，fa表示父节点
int MC = 1e9, n;
vector<int> cen;

void dfs(int x, int f) {
	size[x] = 1; fa[x] = f;
	int mc = 0;
	for (auto & to : g[x]) {
		if (to != f) {
			dfs(to, x);
			mc = max(size[to], mc); // 子节点连通分量
			size[x] += size[to];
		}
	}
	// 父节点那边的连通分量
	mc = max(mc, n - size[x]);
	if (mc < MC) {
		MC = mc;
		cen.clear();
		cen.push_back(x);
	}
	else if (mc == MC) cen.push_back(x);
}

int findLeaf(int x, int f) {
	if (size[x] == 1) return x;
	for (auto & to : g[x]) {
		if (to != f) return findLeaf(to, x);
	}
	return -1;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, u, v;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) g[i].clear();
		cen.clear();
		MC = 1e9;

		for (int i = 1; i < n; ++i) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1, 0);
		if (cen.size() < 2) printf("%d %d\n%d %d\n", u, v, u, v);
		else {
			if (fa[cen[1]] != cen[0]) swap(cen[0], cen[1]);
			int leaf = findLeaf(cen[1], fa[cen[1]]);
			printf("%d %d\n%d %d\n", fa[leaf], leaf, cen[0], leaf);
		}
	}
	
    return 0;
}
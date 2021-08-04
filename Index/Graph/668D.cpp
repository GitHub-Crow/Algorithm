/*
Q: Alice和Bob追逐游戏，Alice一次最多移动da步，Bob一次最多移动db步，Alice先动，如果Alice能够追上Bob则返回True。
A: 分情况讨论

*/
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
#define LOCAL
const int N = 1e5 + 5;
vector<int> e[N];

int diam;
int dep[N];

int dfs(int x, int fa) {
	int len = 0, cur = 0;
	for (auto & v : e[x]) {
		if (v != fa) {
			dep[v] = dep[x] + 1;
			cur = 1 + dfs(v, x);
			diam = max(diam, len + cur);
			len = max(len, cur);
		}
	}
	return len;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	int n, a, b, da, db;
	while (T--) {
		cin >> n >> a >> b >> da >> db;
		for (int i = 1; i <= n; ++i) e[i].clear();
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		diam = 0;
		dep[a] = 0;
		dfs(a, -1);
		if (dep[b] <= da || 2 * da >= diam || 2 * da >= db) cout << "Alice\n";
		else cout << "Bob\n";
	}
	

    return 0;
}
/*
Q: 给定一个无向图，将无向图拆完，拆除节点v的代价为所有连接节点v的节点权重和
问拆完该图需要最少的代价是多少
A: 拆除节点可以变换为拆除边
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e3 + 5;
const LL INF = 1e18;
LL val[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
	}
	int u, v;	
	LL ans = 0;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		ans += min(val[u], val[v]);
	}
	cout << ans << endl;

    return 0;
}
/*
Q：给定一本书，你需要阅读所有章节，但是理解某一章节前需要你理解其他一些章节，请问至少
需要读多少遍才能理解所有章节，规定每次阅读一遍书籍时只能从前往后读，也就时章节序号必须是
单调增的。
A：DAG和拓扑排序。
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
vector<int> sup[N];
int dep[N];
int f[N];
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) sup[i].clear();
		memset(f, 0, sizeof(f));
		memset(dep, 0, sizeof(dep));
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			int k, v;
			cin >> k;
			dep[i] = k;
			for (int j = 1; j <= k; ++j) {
				cin >> v;
				sup[v].push_back(i);
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (dep[i] == 0) {
				q.push(i);
				f[i] = 1;
			}
		}
		int outQueCnt = 0;
		while (!q.empty()) {
			auto t = q.front(); q.pop();
			++outQueCnt;
			for (auto & v : sup[t]) {
				if (v > t) f[v] = max(f[v], f[t]);
				if (v < t) f[v] = max(f[v], f[t] + 1);
				--dep[v];
				if (dep[v] == 0) q.push(v);
			}
		}
		if (outQueCnt < n) cout << "-1\n";
		else cout << *max_element(f + 1, f + 1 + n) << endl;

	}

    return 0;
}	
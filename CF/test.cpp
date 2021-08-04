<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, m;
const int N = 2e5 + 5;
vector<int> g[N];
vector<int> ord;
bool vis[N];

void dfs(int r) {
	vis[r] = true;
	ord.push_back(r);
	for (auto & v : g[r]) {
		if (vis[v]) continue ;
		dfs(v);
	}
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		memset(vis, 0, sizeof(vis));
		ord.clear();
		for (int k = 1; k <= n; ++k) g[k].clear();

		int u, v;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int k = 1; k <= n; ++k) sort(g[k].begin(), g[k].end());
		dfs(1);
		for (auto & v : ord) cout << v << ' ';
		cout << endl;
	}
	

    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int n, m;
const int N = 1e3 + 5;
vector<int> g[N];
int inDeg[N];
map<string, int> re;
vector<string> cache, res;

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n >> m;
	re.clear();
	memset(inDeg, 0, sizeof(inDeg));
	for (int i = 0; i < n; ++i) g[i].clear();
	cache.clear();
	res.clear();

	string u, v;
	int uid, vid;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u;
		if (re.count(u)) uid = re[u];
		else {
			uid = re.size();
			cache.push_back(u);
			re[u] = uid;
		}
		if (re.count(v)) vid = re[v];
		else {
			vid = re.size();
			cache.push_back(v);
			re[v] = vid;
		}
		g[uid].push_back(vid);
		inDeg[vid]++;

	}
	queue<int> dlls;
	for (int i = 0; i < n; ++i) if (inDeg[i] == 0) dlls.push(i);

	while (not dlls.empty()) {
		int len = dlls.size();
		vector<string> layer;
		while (len--) {
			auto cdll = dlls.front(); dlls.pop();
			layer.push_back(cache[cdll]);
			for (auto & dep : g[cdll]) {
				inDeg[dep]--;
				if (inDeg[dep] == 0) dlls.push(dep);
			}
		}
		sort(layer.begin(), layer.end());
		for (auto & dll : layer) res.push_back(dll);
	}
	if (res.size() < n) cout << "true\n";
	else cout << "false\n";
	for (auto & dll : res) cout << dll << ' ';
	cout << endl;

    return 0;
>>>>>>> 4ee0ac854edc3e6e0e70796a21c028a06a3acbf7
}
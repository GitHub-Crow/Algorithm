#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 55;
char g[N][N];
int v[N][N];
int w[N][N];
int T, n, m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool bfs(int i, int j) {
	memset(v, 0, sizeof(v));
	queue<pair<int, int>> que;
	que.push({i, j});
	while (!que.empty()) {
		auto t = que.front(); que.pop();
		int i = t.first, j = t.second;
		if (v[i][j]) continue ;
		if (w[i][j]) return true;
		v[i][j] = 1;
		if (i == n - 1 && j == m - 1) {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (v[i][j]) w[i][j]= 1;
			return true;
		}
		for (int k = 0; k < 4; ++k) {
			int ni = i + dx[k], nj = j + dy[k];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m || v[ni][nj]) continue ;
			if (g[ni][nj] == '.' || g[ni][nj] == 'G') que.push({ni, nj});
		}
	}
	return false;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cin >> g[i][j];
			}
		memset(w, 0, sizeof(w));
		bool f = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == 'B') {
					for (int k = 0; k < 4; ++k) {
						int ni = i + dx[k], nj = j + dy[k];
						if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue ;
						if (g[ni][nj] == 'G') f = false;
						if (g[ni][nj] == '.') g[ni][nj] = '#';
					}
				}
			}
		if (!f) cout << "NO\n";
		else {
			for (int i = 0; i < n; ++i) 
				for (int j = 0; j < m; ++j) 
					if (f && !w[i][j] && g[i][j] == 'G') f &= bfs(i, j);
			if (f) cout << "YES\n";
			else cout << "NO\n";
		}
	}

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int n, m;
const int N = 55;
char g[N][N];
bool v[N][N];
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool dfs(int x, int y, int fx, int fy) {
	char co = g[x][y];
	bool r = false;
	v[x][y] = true;
	for (int k = 0; k < 4; ++k) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != co) continue ;
		if (nx != fx || ny != fy) {
			if (v[nx][ny]) {
				r = true;
				break ;
			}
			r |= dfs(nx, ny, x, y);
		}
	}
	return r;
}

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> g[i][j];
	bool ans = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j]) continue ;
			ans |= dfs(i, j, -1, -1);
			if (ans) break ;
		}
		if (ans) break ;
	}
	cout << (ans ? "Yes\n" : "No\n");
    return 0;
}
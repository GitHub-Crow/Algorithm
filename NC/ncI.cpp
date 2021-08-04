#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 1e3 + 5;
char cell[N][N];
bool access[N][N];
bool vis[N][N];
int m, n;

bool dfs(int i, int j) {
	if (i < 0 || i >= m || j < 0 || j >= n) return false;
	if (vis[i][j]) return access[i][j];
	vis[i][j] = true;
	auto c = cell[i][j];
	if (c == 'W') return access[i][j] = dfs(i - 1, j);
	else if (c == 'S') return access[i][j] = dfs(i + 1, j);
	else if (c == 'A') return access[i][j] = dfs(i, j - 1);
	else if (c == 'D') return access[i][j] = dfs(i, j + 1);
	return false;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> m >> n;

	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) {
			cin >> cell[i][j];
			vis[i][j] = false;
			access[i][j] = true;
		}
	int ans = 0;
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) {
			dfs(i, j);
			if (!access[i][j]) ++ans;
		}
	cout << ans;
	

    return 0;
}
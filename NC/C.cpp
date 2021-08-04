#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
#define LOCAL

const int N = 1e3 + 5;
int a[N][N];

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	int n, m, sx, sy, d, r;
	while (T--) {
		cin >> n >> m >> sx >> sy >> d >> r;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> a[i][j];

		queue<PII> que;
		que.push({sx, sy});
		set<int> cache;
		int steps = d + 1;
		while (steps--) {
			int len = que.size();
			while (len--) {
				auto t = que.front(); que.pop();
				int x = t.first, y = t.second;
				if (a[x][y] > 0) cache.insert(a[x][y]);
				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx > n || ny < 0 || ny > m || a[nx][ny] == -1) continue ;
					que.push({nx, ny});
				}
			}
		}
		vector<int> u(cache.begin(), cache.end());
		if (u.size() < r) {
			cout << "no\n";
			continue ;
		}
		int ret = 1e9;
		for (int L = 0, R = r - 1; R < u.size(); ++L, ++R) {
			ret = min(ret, u[R] - u[L]);
		}
		cout << ret << endl;
	}
	

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int T, n, m;
const int N = 505;
bool f[N][N];
bool nf[N][N];
char g[N][N];



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
			for (int j = 0; j < m; ++j) 
				cin >> g[i][j];
		memset(f, 0, sizeof(f));
		LL ans = 0;

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) {
				if (g[i][j] == '*') {
					f[i][j] = true;
					++ans;
				}
			}

		bool hasTree = true;
		while (hasTree) {
			hasTree = false;
			memset(nf, 0, sizeof(nf));
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					if (!f[i][j]) continue ;
					int iL = i + 1, jL = j - 1, iR = i + 1, jR = j + 1, iM = i + 1, jM = j;
					if (iL >= n or jL < 0 or iR >= n or jR >= m or iM >= n) continue ;
					nf[i][j] = f[iL][jL] and f[iR][jR] and f[iM][jM];
					if (nf[i][j]) {
						++ans;
						hasTree = true;
					}
				}
			memcpy(f, nf, sizeof(f));
		}
		cout << ans << endl;
	}
	

    return 0;
}
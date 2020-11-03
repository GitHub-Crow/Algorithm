#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	while (T--) {
		int m, n, a, b;
		cin >> m >> n >> a >> b;
		vector<vector<int>> s(m, vector<int>(n));

		for (int i = 0; i < m; ++i) {
			int c, nc;
			cin >> c;
			s[i][0] = c;
			for (int j = 1; j < n; ++j) {
				cin >> nc;
				s[i][j] = nc - c;
				c = nc;
			}
		}
		bool f = true;
		for (int i = 0; i <= m - a; ++i) {
			for (int j = 0; j <= n - b; ++j) {
				if (s[i][j] > 0) {
					int x = s[i][j];
					for (int k = i; k < i + a; ++k) {
						s[k][j] -= x;
						if (j + b < n) s[k][j + b] += x;
					}
				} 
				else if (s[i][j] == 0) continue ;
				else {
					f = false;
				}
			}
		}
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j]) f = false;
			
		if (f) cout << "^_^\n";
		else cout << "QAQ\n";
	}

	

    return 0;
}
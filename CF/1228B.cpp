#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int g[N][N];
int h, w, r, c;


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	memset(g, 0, sizeof(g));
	cin >> h >> w;
	LL ans = 1;
	for (int i = 0; i < h; ++i) {
		cin >> r;
		for (int j = 0; j < r; ++j) 
			if (g[i][j] != 2) g[i][j] = 1;
			else ans = 0;
		if (g[i][r] != 1) g[i][r] = 2;
		else ans = 0;
	}
	for (int i = 0; i < w; ++i) {
		cin >> c;
		for (int j = 0; j < c; ++j) 
			if (g[j][i] != 2) g[j][i] = 1;
			else ans = 0;
		if (g[c][i] != 1) g[c][i] = 2;
		else ans = 0;
	}
	if (!ans) cout << "0\n";
	else {
		for (int i = 0; i < h; ++i) 
			for (int j = 0; j < w; ++j)
				if (!g[i][j])
					ans = 2 * ans % MOD;	

		cout << ans << endl;	
	}

    return 0;
}
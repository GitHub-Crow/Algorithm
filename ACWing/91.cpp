#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 20, INF = 0x3f;
int a[N][N];
int f[(1 << N)][N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) cin >> a[i][j];
	memset(f, INF, sizeof(f));
	f[0][0] = 0;
	for (int s = 1; s < (1 << n); ++s) {
		for (int k = 0; k < n; ++k) {
			if (s >> k & 1) {
				for (int i = 0; i < n; ++i) {
					if (s >> i & 1 and s != i) {
						f[s][k] = min(f[s][k], f[s ^ (1 << k)][i] + a[i][k]);
					}
				}
			}
		}
	}
	cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}
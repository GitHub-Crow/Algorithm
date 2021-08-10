#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL


int n, m, q;
const int N = 2e5 + 5;
int higher[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v;
	memset(higher, 0, sizeof(higher));
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		if (u > v) higher[v]++;
		if (v > u) higher[u]++;
	}
	int ans = 0;
	for (int k = 1; k <= n; ++k) if (higher[k] == 0) ++ans;
	cin >> q;
	for (int k = 1; k <= q; ++k) {
		int key;
		cin >> key;
		if (key == 3) cout << ans << endl;
		else {
			cin >> u >> v;
			if (key == 1) {
				if (u > v) {
					if (higher[v] == 0) --ans;
					higher[v]++;
				}
				if (v > u) {
					if (higher[u] == 0) --ans;
					higher[u]++;
				}
			}
			if (key == 2) {
				if (u > v) {
					higher[v]--;
					if (higher[v] == 0) ++ans;
				}
				if (v > u) {
					higher[u]--;
					if (higher[u] == 0) ++ans;
				}
			}
		}
	}

    return 0;
}
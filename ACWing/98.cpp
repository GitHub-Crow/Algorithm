#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

int f3t[15], f4t[15];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	memset(f3t, 0x3f, sizeof(f3t));
	memset(f4t, 0x3f, sizeof(f4t));

	f3t[1] = f4t[1] = 1;
	for (int k = 2; k <= n; ++k) f3t[k] = 1 + 2 * f3t[k - 1];
	for (int k = 2; k <= n; ++k) {
		for (int o = 1; o < k; ++o) {
			f4t[k] = min(f4t[k], 2 * f4t[o] + f3t[k - o]);
		}
	}
	cout << f4t[n] << endl;
    return 0;
}
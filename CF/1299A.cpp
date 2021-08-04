#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e5 + 5;
int a[N], bits[32];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n;
	cin >> n;
	memset(bits, 0, sizeof(bits));
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < 30; ++k) {
			if (a[i] >> k & 1) {
				if (!bits[k]) bits[k] = i;
				else bits[k] = -1;
			}
		}
	}
	unordered_set<int> re;

	for (int k = 30; k >= 0; --k) {
		if (bits[k] > 0 && !re.count(bits[k])) {
			cout << a[bits[k]] << ' ';
			re.insert(bits[k]);
		}
	}
	for (int k = 1; k <= n; ++k) {
		if (re.count(k)) continue ;
		cout << a[k] << ' ';
	}
	cout << endl;
	

    return 0;
}
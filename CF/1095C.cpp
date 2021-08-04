#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL



int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, k;
	cin >> n >> k;
	int tot = 0;
	for (int i = 0; i <= 30; ++i) if (n >> i & 1) ++tot;
	if (tot > k || k > n) cout << "NO";
	else {
		cout << "YES\n";
		for (int i = 30; i >= 0; --i) {
			while (k && n - (1 << i) >= k - 1) {
				cout << (1 << i) << ' ';
				n = n - (1 << i);
				--k;
			}

		}
		cout << endl;
	}
	

    return 0;
}
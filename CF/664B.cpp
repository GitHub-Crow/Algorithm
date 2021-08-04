#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	cout << x << ' ' << y << endl;
	for (int k = 1; k <= m; ++k) {
		if (k != y) cout << x << ' ' << k << endl;
	}
	bool isInverse = true;

	for (int i = 1; i <= n; ++i) {
		if (i == x) continue ;
		if (isInverse) {
			for (int j = m; j; --j) cout << i << ' ' << j << endl;
			isInverse = false;
		} else {
			for (int j = 1; j <= m; ++j) cout << i << ' ' << j << endl;
			isInverse = true;

		}
	}

    return 0;
}
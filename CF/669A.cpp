#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int a;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			if (a) ++c1;
			else ++c0;
		}
		int x;
		if (c0 >= c1) {
			cout << n / 2 << endl;
			for (int k = 0; k < n/2 - 1; ++k) cout << 0 << ' ';
			cout << 0 << endl;
		}
		else {
			int m = (((n / 2) & 1) ? n / 2 : n / 2 - 1);
			cout << m + 1 << endl;
			for (int k = 0; k < m; ++k) cout << 1 << ' ';
			cout << 1 << endl;
		}
	}
	

    return 0;
}
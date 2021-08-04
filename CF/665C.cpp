#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define LOCAL

const int N = 1e5 + 5;
int a[N];
int b[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	while (T--) {
		int n, m = 1e9;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			m = min(m, a[i]);
		}

		sort(b, b + n);
		bool f = true;
		for (int k = 0; k < n; ++k) {
			if (a[k] != b[k] && a[k] % m > 0) f = false;
		}
		if (f) cout << "YES\n";
		else cout << "NO\n";
	}	

    return 0;
}
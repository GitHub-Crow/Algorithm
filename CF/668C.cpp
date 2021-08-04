#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL

const int N = 4e5;
char a[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		bool f = true;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = k; i < n; ++i) {
			if (a[i % k] == '?') a[i % k] = a[i];
			else {
				if (a[i] != '?' && a[i % k] != a[i]) {
					f = false;
					break ;
				}
			}
		}
		int zeroc = 0, onec = 0;
		for (int i = 0; i < k; ++i) {
			if (a[i] == '0') zeroc++;
			else if (a[i] == '1') onec++;
		}
		// printf("%d, %d\n", zeroc, onec);
		if (k < 2*max(zeroc, onec)) f = false;
		if (f) cout << "YES\n";
		else cout << "NO\n";
	}
	

    return 0;
}
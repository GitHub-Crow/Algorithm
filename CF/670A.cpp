#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;

#define LOCAL

int a[105];

int main(int argc, char * argv[]) 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T, n, x;
	cin >> T;
	while (T--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			a[x]++;
		}
		int ans = 0, c = 2;
		for (int i = 0; i < 105 && c; ++i) {
			if (a[i] == 0) {
				ans += c * i;
				break ;
			} else if (a[i] == 1) {
				if (c < 2) continue ;
				ans += i;
				--c;
			}
		}
		cout << ans << endl;
	}
	

    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int a[N];


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int b[n];
	int j = 0;
	b[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			++j;
			b[j] = 0;
		}
		++b[j];
	}
	unique(a, a + n);
	LL s1 = 1ll * a[0] * b[0];
	LL s0 = 0;
	for (int i = 1; i <= j; ++i) {
		LL d = 1ll * a[i] * b[i];
		if (a[i] == a[i - 1] + 1) {
			LL ns0 = max(s0, s1);
			LL ns1 = d + s0;
			s0 = ns0;
			s1 = ns1;
		}
		else {
			LL ns0 = max(s0, s1);
			LL ns1 = d + ns0;
			s0 = ns0;
			s1 = ns1;
		}
	}
	cout << max(s0, s1) << endl;

    return 0;
} 
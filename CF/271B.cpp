#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 1e5 + 5;
int a[N];
int n, m;

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	cin >> n;
	a[0] = 0;
	int x;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		auto it = lower_bound(a + 1, a + n + 1, x) - a;
		cout << it << endl;
	}

	

    return 0;
}
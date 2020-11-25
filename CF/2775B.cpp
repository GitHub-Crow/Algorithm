#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

#define LOCAL


const int N = 105;
int a[N], b[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int pa = 0, pb = 0, ans = 0;
	while (pa < n && pb < m) {
		if (abs(a[pa] - b[pb]) <= 1) {
			++ans;
			++pa; ++ pb;
		}
		else {
			if (a[pa] > b[pb]) ++pb;
			else ++pa;
		}
	}
	cout << ans;
    return 0;
}
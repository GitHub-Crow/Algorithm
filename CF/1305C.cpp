#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 2e5 + 5;
int a[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n > m) {
		cout << 0 << endl;
	}
	else {
		LL ans = 1;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) ans = ans * abs(a[i] - a[j]) % m;
		cout << ans << endl;
	}
	

    return 0;
}
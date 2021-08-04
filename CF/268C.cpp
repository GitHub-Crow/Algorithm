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
	int m, n;
	cin >> m >> n;
	int k = min(m, n);
	cout << k + 1 << endl;
	for (int i = 0; i <= k; ++i) {
		cout << i << ' ' << k - i << endl;
	}
	

    return 0;
}
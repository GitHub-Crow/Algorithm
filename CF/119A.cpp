#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;

#define LOCAL

const int N = 5e3;
int f[N];

int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	memset(f, -1, sizeof(f));
	
	f[0] = 0;
	for (int k = 1; k <= n; ++k) {
		if (k >= a && f[k - a] >= 0) f[k] = max(f[k], f[k - a] + 1);
		if (k >= b && f[k - b] >= 0) f[k] = max(f[k], f[k - b] + 1);
		if (k >= c && f[k - c] >= 0) f[k] = max(f[k], f[k - c] + 1);
	}
	cout << f[n] << endl;

    return 0;
}
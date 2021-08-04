#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

#define LOCAL
const int N = 1e6 + 5;
bool f[N];

void init() {
	f[1] = true;
	for (int k = 2; k < N; ++k) {
		if (f[k]) continue ;
		int w = 2 * k;
		while (w < N) {
			f[w] = true;
			w += k;
		}
	}
}


int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	init();
	int n;
	LL x;
	cin >> n;
	while (n--) {
		cin >> x;
		LL t = sqrt(x);
		if (t * t != x) cout << "NO\n";
		else {
			if (!f[t]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	

    return 0;
}
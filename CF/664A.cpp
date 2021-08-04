#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
#define LOCAL

bool gen(LL& r, LL& g, LL& b, LL& w) {
	int cnt = 0;
	if (r & 1) ++cnt;
	if (g & 1) ++cnt;
	if (b & 1) ++cnt;
	if (w & 1) ++cnt;
	return cnt < 2;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif

	int T;
	cin >> T;
	LL r, g, b, w;
	while (T--) {
		cin >> r >> g >> b >> w;
		bool f = false;
		if (gen(r, g, b, w)) f = true;
		else {
			if (r && g && b) {
				--r; --g; --b;
				w += 3;
			}
			if (gen(r, g, b, w)) f = true;

			if (r && g && b) {
				--r; --g; --b;
				w += 3;
			}
			if (gen(r, g, b, w)) f = true;
			LL tmp = min({r, g, b});
			r -= tmp; g -= tmp; b -= tmp;
			w += 3*tmp;
			if (gen(r, g, b, w)) f = true;
		}
		if (f) cout << "YES\n";
		else cout << "NO\n";	
	}

    return 0;
}
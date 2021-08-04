#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	int a, b, x, y, n;
	while (T--) {
		cin >> a >> b >> x >> y >> n;
		if (max(x, a - n) > max(y, b - n)) {
			if (b - n > y) {
				b -= n;
				n = 0;
			} else {
				n -= b - y;
				b = y;
			}
		} else {
			if (a - n > x) {
				a -= n;
				n = 0;
			} else {
				n -= a - x;
				a = x;
			}
		}
		if (n) {
			if (a > x) a = max(x, a - n);
			if (b > y) b = max(y, b - n);
		}
		cout << (LL)a * (LL)b << endl;
	}
	

    return 0;
}
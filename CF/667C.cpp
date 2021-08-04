#include <iostream>

using namespace std;
typedef long long LL;
#define LOCAL
int gen(int x, int n) {
	if (x % n == 0) return x / n;
	return gen(x, n - 1);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("data.in", "r", stdin);
	#endif
	int T;
	cin >> T;
	int n, x, y;
	LL q, ed;
	while (T--) {
		cin >> n >> x >> y;
		if (y - n < x) {
			q = 1;
			ed = max(y, n);
		} else {
			q = gen(y - x, n - 1);
			ed = y + (n - (y - 1) / q - 1)*q;
			ed = max(ed, (LL)y); // avoid miss y
		}
		for (int k = n - 1; k > 0; --k) {
			cout << ed - q*k << ' ';
		}
		cout << ed << endl;
	}
	

    return 0;
}